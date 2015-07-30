### Installation
**Make** and a **C++11** compatible compiler are required. Clone the repo and type ``make all`` in your favourite shell.

Uses jsoncons library (https://github.com/danielaparker/jsoncons).


### Usage
```
json2geojson.exe -i input.json -o output.json -f format
```

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

### Output Sample
FeatureCollection of points:
```
{
  "features" :
  [{
      "geometry" : {
        "coordinates" :
        "type" : "Point"
      },
      "properties" : {
        "index" : 0
      },
      "type" : "Feature"
    }, {
      "geometry" : {
        "coordinates" :
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
    ],
    "type" : "LineString"
  },
  "properties" : null,
  "type" : "Feature"
}


Brought to you with :heart: by:

&copy; _Physics of Complex Systems Laboratory - Physics and Astronomy Department - University of Bologna_

