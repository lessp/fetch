#!/bin/bash

for package in fetch-core fetch-native-lwt 
do
  cp $package.json ./src/$package/package.json
  cp $package.opam ./src/$package
  cp LICENSE ./src/$package
done
