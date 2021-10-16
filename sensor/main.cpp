#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;
// splitrar sensorerna och värdet
vector<string> split_string(string str, char separator){
    int current_index = 0, i = 0, startIndex = 0, endIndex = 0;
    vector<string> strings;
    while(i < str.length()) {
        if(str[i] == separator || i == str.length()) {
            endIndex = i;
            string subStr;
            subStr.append(str, startIndex, endIndex - startIndex);
            strings.push_back(subStr);
            current_index++;
            startIndex = endIndex + 1;
        }
        i++;
    }
    return strings;
}
int main() {
// Läser av från textfilen och skriver av
    string line;
    ifstream myfile("/Users/monael-robaiy/desktop/sensor/sensorer");
    if (myfile.is_open()) {
        getline(myfile, line);
        cout << line << '\n';

        myfile.close();
    } else cout << "Unable to open file";
    auto strings = split_string(line, ';');
    for(auto s : strings){
        cout << s << endl;


        /*
         * Denna koden ändrar värdet från textfilen på 10 procent av sensorerna och vilar  i en sekund.
         Denna koden är för python:
          while True:
            with open('sensorer', 'r') as infile:
                line = infile.readline().split(';')
                num_to_change = int(len(line) // 2*0.1)
                indexes = list(range(1, len(line), 2))
                for _ in range(num_to_change):
                    index = random.choice(indexes)
                    value = line[index]
                    line[index]  = 'false' if value == 'true' else 'true'
                    line_to_write = ';'.join(line)
                with open('sensorer', 'w') as out_file:
                    out_file.write(line_to_write)
                 time.sleep(1)

*/


    }




    return 0;
}
