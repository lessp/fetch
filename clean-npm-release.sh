#!/bin/bash

for package in fetch-core fetch-native-lwt 
do
  rm ./src/$package/package.json
  rm ./src/$package/$package.opam
  rm ./src/$package/LICENSE
  rm ./src/$package/dune-project
done
