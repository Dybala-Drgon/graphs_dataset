#include <sstream>
#include<vector>
#include<fstream>
#include <iostream>
#include<algorithm>
#include<filesystem>

using namespace std;


const string baseDIr = "/mnt/i/projects/buaa/data/data2/";
const string outputDIr = "/mnt/i/projects/buaa/data/data2/done/";

ifstream nums(baseDIr+"generate.data");

vector<string>get_file_name(string dir);

void process_data(const string& file_path);

int main(){
    auto files = get_file_name(baseDIr);
    for(const string& file:files){
        process_data(file);
    }
}

vector<string>get_file_name(string dir){
    vector<string>res;
    for(const auto &file: std::filesystem::directory_iterator(dir)){
        string name = file.path();
        if (name.find(".txt")!=-1&& name != "CMakeLists.txt" ){

            res.push_back(name);
        }
    }
    return res;
}

void process_data(const string& file_path){
    cout<<"read "<<file_path<<endl;
    ifstream ifs(file_path);
    if (!ifs.is_open()){ 
        cout<<"error"<<endl;
        exit(1);
    }
    string line;
    long long id1;
    long long id2;
    double timestamp;
    int duration;
    double wight;
    stringstream ss;
    while(ifs >> id1>>id2>>wight>>timestamp){
        if (nums.eof()){
            nums.close();
            nums.open(baseDIr+"generate.data");
            cout<<file_path<<" end, loop from begin"<<endl;
        }
        nums>>duration;

        ss<<id1<<" "<<id2<<" "<<long(timestamp)<<" "<<duration<<"\n";
    }
    int idx = file_path.find("out");
    idx+=4;
    string file_name = file_path.substr(idx);
    
    ofstream ofs(outputDIr+file_name);
    ofs<<ss.str();

}
