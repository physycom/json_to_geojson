EXE = json2geojson.exe

all:
	g++ -std=c++11 -o $(EXE) -I. json_to_geojson.cpp -fpermissive
