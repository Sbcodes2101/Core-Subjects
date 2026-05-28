#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    // File ko open krna
    // ofstream fout;
    // fout.open("zoom.txt"); // create krke open krdega
    // // Write kr sakta hun
    // fout<<"Hello India";
    // fout.close(); //Resource release kar pauuon

    vector<int> arr(5);
    cout<<"Enter the input:";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }

    ofstream fout;
    fout.open("zoom.txt");

    for(int i=0;i<=arr.size();i++){
        fout<<arr[i];
    }

    fout<<"\nSorted data\n"
    sort(arr.begin(),arr.end());

    for(int i=0;i<5;i++){
        fout<<arr[i]<<" ";
    };

    fout.close();

}