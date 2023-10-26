#!/bin/bash

rm -r tmp 2> /dev/null
mkdir tmp
rm dirSensors.log 2> /dev/null

ls ${2} > tmp/tmp.txt
COUNT=$(ls ${2} | wc -l)

while [[ true ]]; do
  sleep ${1}
  NEWCOUNT=$(ls ${2} | wc -l)
  if [[ ${COUNT} -gt ${NEWCOUNT} ]]; then
    ls ${2} > tmp/diff.txt
    FILES=$(diff tmp/tmp.txt tmp/diff.txt | grep "<.*" | cut -d' ' -f2)
    ls ${2} > tmp/tmp.txt
    echo -e "$(date +"[%d-%m-%Y %H:%M:%S]") Alteração! ${COUNT} -> ${NEWCOUNT}. Removidos: $(for VAR in ${FILES}; do
      echo -n "${VAR} "
    done)\n" >> dirSensors.log
    COUNT=${NEWCOUNT}
    clear
    cat dirSensors.log
  fi
  if [[ ${COUNT} -lt ${NEWCOUNT} ]]; then
    ls ${2} > tmp/diff.txt
    FILES=$(diff tmp/tmp.txt tmp/diff.txt | grep ">.*" | cut -d' ' -f2)
    ls ${2} > tmp/tmp.txt
    echo -e "$(date +"[%d-%m-%Y %H:%M:%S]") Alteração! ${COUNT} -> ${NEWCOUNT}. Adicionados: $(for VAR in ${FILES}; do
      echo -n "${VAR} "
    done)\n" >> dirSensors.log
    COUNT=${NEWCOUNT}
    clear
    cat dirSensors.log
  fi
done
