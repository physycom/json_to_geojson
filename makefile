EXE = json_to_geojson.exe

all: dirtree
	$(CXX) -std=c++11 -o bin/$(EXE) -Isrc/jsoncons/src src/json_to_geojson.cpp 

dirtree:
	@mkdir -p bin

clean:
	rm -f bin/$(EXE)

cleanall:
	rm -rf bin obj
