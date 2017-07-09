---
documentclass: physycomen
title:  "json_to_geojson"
author: "Di Cristina, Sinigardi"
---

<a href="http://www.physycom.unibo.it"> 
<div class="image">
<img src="https://cdn.rawgit.com/physycom/templates/697b327d/logo_unibo.png" width="90" height="90" alt="© Physics of Complex Systems Laboratory - Physics and Astronomy Department - University of Bologna"> 
</div>
</a>
<a href="https://travis-ci.org/physycom/json_to_geojson"> 
<div class="image">
<img src="https://travis-ci.org/physycom/json_to_geojson.svg?branch=master" width="90" height="20" alt="Build Status"> 
</div>
</a>
<a href="https://ci.appveyor.com/project/cenit/json-to-geojson"> 
<div class="image">
<img src="https://ci.appveyor.com/api/projects/status/gfg9mo499y148bfa?svg=true" width="90" height="20" alt="Build Status"> 
</div>
</a>

### Purpose
This tool has been written to convert data to the [GeoJson](http://geojson.org/) format from our .json structure, in order to be able to import data in our tools from the GeoJson standard.


### Installation
**CMake** and a **C++11** compatible compiler are required. To build the executable, clone the repo and then type  
```
mkdir build ; cd build ; cmake .. ; cmake --build .
```
With CMake you can also deploy projects for the most common IDEs.  
Contains [jsoncons](https://github.com/danielaparker/jsoncons) as a git submodule.


### Usage
```
json_to_geojson.exe -i input.json -o output.json -f format
```
where `input.json` must be an existing and valid .json file with at least 'lat' and 'lon' keys in each element, while `output.json` is the name of the produced GeoJson file.

The flag -f specifies the type of the output geojson, and is one of 'p', 'm', 'fm', 'l', 'fl' (without quotes):
- 'p' for a FeatureCollection of points,
- 'm' for a simple MultiPoint,
- 'fm' for a Feature MultiPoint,
- 'l' for a simple LineString,
- 'fl' for a Feature LineString.

### Input Sample
Either array-style:
```
[
    {
        "your_key1":"your_value",
        "your_key2":"your_value",
        "lat" : 44.498950,
        "lon" : 11.353606
    },
    {
        "your_key1":"your_value",
        "your_key2":"your_value",
        "lat" : 44.498595,
        "lon" : 11.354939
    },
    {
        "your_key1":"your_value",
        "your_key2":"your_value",
        "lat" : 44.498257,
        "lon" : 11.355894,
        "alt" : 10.0
    }
]
```
or object-style:
```
{
    "gps_record_0000001":
    {
        "your_field":"your_content",
        "lat":44.5021611,
        "lon":11.3648926
        "alt" : 56
    },
    "gps_record_0000002":
    {
        "another_field":"another_content",
        "lat":44.5021381,
        "lon":11.3648768
    }
}
```

### Output Sample
FeatureCollection of points:
```
{
  "features" :
  [{
      "geometry" : {
        "coordinates" :
        [11.3648926, 44.5021611, 56],
        "type" : "Point"
      },
      "properties" : {
        "index" : 0
      },
      "type" : "Feature"
    }, {
      "geometry" : {
        "coordinates" :
        [11.3648768, 44.5021381],
        "type" : "Point"
      },
      "properties" : {
        "index" : 1
      },
      "type" : "Feature"
    }
  ],
  "type" : "FeatureCollection"
}
```
simple MultiPoint:
```
{
  "coordinates" :
  [
    [11.3648926, 44.5021611, 56],
    [11.3648768, 44.5021381]
  ],
  "type" : "MultiPoint"
}
```
Feature MultiPoint:
```
{
  "geometry" : {
    "coordinates" :
    [
      [11.3648926, 44.5021611, 56],
      [11.3648768, 44.5021381]
    ],
    "type" : "MultiPoint"
  },
  "properties" : null,
  "type" : "Feature"
}
```
simple LineString:
```
{
  "coordinates" :
  [
    [11.3648926, 44.5021611, 56],
    [11.3648768, 44.5021381]
  ],
  "type" : "LineString"
}
```
Feature LineString:
```
{
  "geometry" : {
    "coordinates" :
    [
      [11.3648926, 44.5021611, 56],
      [11.3648768, 44.5021381]
    ],
    "type" : "LineString"
  },
  "properties" : null,
  "type" : "Feature"
}
```

More details can be found in our technical description of the file formats published [here](https://github.com/physycom/file_format_specifications/blob/master/formati_file.md)


