#!/bin/bash
CONVERTER="./json2geojson.exe"
for ijson in data/*.json; do
	out="out/${ijson%.*}_out_p.json"
	$CONVERTER -i $ijson -o $out -f p
done
