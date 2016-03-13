#include <iostream>
#include <vector>

using namespace std;


vector<int> productExceptSelf(vector<int>& nums){

    int len=nums.size();

    vector<int> left(len,1);
    vector<int> right(len,1);
    vector<int> result(len,1);

    for(int i=1;i<len;i++){
        left[i]=left[i-1]*nums[i-1];
    }

    for(int i=len-2;i>=0;i--){
        right[i]=right[i+1]*nums[i+1];
    }

    for(int i=0;i<len;i++){
        //result.push_back(left[i]*right[i]);
        result[i]=left[i]*right[i];
    }

    return result;

}



vector<int> productExceptSelf1(vector<int>& nums){
    int len=nums.size();

    vector<int> result(len,1);

    for(int i=1;i<len;i++){
        result[i]=result[i-1]*nums[i-1];
    }

    int right=1;

    for(int i=len-2;i>=0;i--){
        right *=nums[i+1];
        result[i]=result[i]*right;
    }

    return result;

}


int main() {

    cout << "Hello, World!" << endl;

    vector<int> testVector={1,2,3,4};

    vector<int> ret=productExceptSelf(testVector);

    cout<<"ret:"<<endl;
    for(auto i=ret.begin();i!=ret.end();i++){
        cout<<*i<<endl;
    }

    cout<<"ret1:"<<endl;
    vector<int> ret1=productExceptSelf1(testVector);
    for(auto i=ret1.begin();i!=ret1.end();i++){
        cout<<*i<<endl;
    }

    return 0;
}