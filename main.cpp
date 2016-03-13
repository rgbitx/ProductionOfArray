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



int main() {

    cout << "Hello, World!" << endl;

    vector<int> testVector={1,2,3,4};

    vector<int> ret=productExceptSelf(testVector);

    for(auto i=ret.begin();i!=ret.end();i++){
        cout<<*i<<endl;
    }


    return 0;
}