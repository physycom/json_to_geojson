/* Copyright 2015--2018 - Marco Di Cristina, Stefano Sinigardi */

/***************************************************************************
This file is part of json_to_geojson.

json_to_geojson is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

json_to_geojson is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with json_to_geojson. If not, see <http://www.gnu.org/licenses/>.
***************************************************************************/

#include <iostream>
#include <jsoncons/json.hpp>

using namespace std;
using namespace jsoncons;

int main(int argc, char** argv) {
  cout << "Usage: " << argv[0] << " -i [input.json] -o [output.json] -f [output format]" << endl;
  cout << "\t- [input.json] geojson file to parse" << endl;
  cout << "\t- [output.kml] json file produced by this utility (physycom standard)" << endl;
  cout << "\t- Input file can be coded using one of these standard formats:\n"
    << "\t\t FeatureCollection (supported),\n"
    << "\t\t MultiPoint (todo),\n"
    << "\t\t Feature_MultiPoint (todo),\n"
    << "\t\t LineString (todo),\n"
    << "\t\t Feature_LineString (todo)" << endl;

  string input_name, output_name;

  if (argc > 2) { /* Parse arguments, if there are arguments supplied */
    for (int i = 1; i < argc; i++) {
      if ((argv[i][0] == '-') || (argv[i][0] == '/')) {       // switches or options...
        switch (tolower(argv[i][1])) {
        case 'i':
          input_name = argv[++i];
          break;
        case 'o':
          output_name = argv[++i];
          break;
        default:    // no match...
          cout << "Flag \"" << argv[i] << "\" not recognized. Quitting..." << endl;
          exit(1);
        }
      }
      else {
        cout << "Flag \"" << argv[i] << "\" not recognized. Quitting..." << endl;
        exit(11);
      }
    }
  }
  else { cout << "No flags specified. Read usage and relaunch properly." << endl; exit(111); }

  if (input_name.size() > 5) {
    if (input_name.substr(input_name.size() - 5, 5) != ".json") {
      cout << input_name << " is not a valid .json file. Quitting..." << endl;
      exit(2);
    }
  }
  else {
    cout << input_name << " is not a valid .json file. Quitting..." << endl;
    exit(22);
  }

  ifstream input_file(input_name);
  if (!input_file.is_open()) {
    cout << "FAILED: Input file " << input_name << " could not be opened." << endl;
    cout << "Hit ENTER to close.\n"; cin.get();
    exit(222);
  }
  else { cout << "SUCCESS: file " << input_name << " opened!\n"; }
  input_file.close();

  if (output_name.size() > 5) {
    if (output_name.substr(output_name.size() - 5, 5) != ".json") {
      cout << output_name << " is not a valid .json file. Quitting..." << endl;
      exit(3);
    }
  }
  else {
    cout << output_name << " is not a valid .json file. Quitting..." << endl;
    exit(33);
  }

  json geojson_records = json::parse_file(input_name);
  json outjson;

  if(geojson_records["type"] == "FeatureCollection") {
      // todo
  }

  ofstream output_file(output_name);
  if (!output_file.is_open()) {
    cout << "FAILED: Output file " << output_name << " could not be opened." << endl;
    cout << "Hit ENTER to close.\n"; cin.get();
    exit(333);
  }
  else { cout << "SUCCESS: file " << output_name << " opened!\n"; }
  output_file << pretty_print(outjson) << endl;
  output_file.close();

  return 0;
}
