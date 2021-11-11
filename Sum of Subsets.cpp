#include <bits/stdc++.h>

using namespace std;

int inputSize;
int targetSum;
int numberOfSubsets=0;

void sumOfSubset(int currentSum, int currentItem, int r, vector<int> weight, vector<int> itemTrack)
{
    itemTrack[currentItem]=1;
    if((currentSum+weight[currentItem])==targetSum)
    {
        cout<<"\nSolution of Subset number " << ++numberOfSubsets << endl;
        for(int i=1; i<=currentItem; i++)
        {
            if(itemTrack[i]==1)
                cout<<weight[i] <<" ";
        }
        cout << "\nIn fixed tuple form it is : ";
        for(int i=1; i<=inputSize; i++)
        {
            cout<<" "<<itemTrack[i];
        }
        cout << endl;
    }else if(currentSum+weight[currentItem]+weight[currentItem+1]<=targetSum){
        sumOfSubset(currentSum+weight[currentItem],currentItem+1,r-weight[currentItem], weight, itemTrack);
    }

    if((currentSum+r-weight[currentItem]>=targetSum)&&
            (currentSum+weight[currentItem+1])<=targetSum){
        itemTrack[currentItem]=0;
        sumOfSubset(currentSum,currentItem+1,r-weight[currentItem], weight, itemTrack);
    }

}


int main()
{

    vector<int> weight;
    vector<int> itemTrack;
    cout << "Enter size : ";
    cin >> inputSize;
    weight.push_back(NULL);
    itemTrack.push_back(NULL);
    int sum=0;
    cout << "Enter " << inputSize << "elements" << endl;
    for(int i = 1; i <= inputSize; i++)
    {
        int input;
        cin >> input;
        weight.push_back(input);
        sum += input;
        itemTrack.push_back(0);
    }

    sort(weight.begin()+1,weight.end()+1);


    cout << "Enter target sum: ";
    cin >> targetSum;

    if(weight[1]>targetSum || sum<targetSum)
    {
        cout << "No subsets possible";
        return 0;
    }

    sumOfSubset(0,1,sum,weight,itemTrack);

    return 0;
}

/*
4
11
13
24
7
31



6
5
10
12
13
15
18
30
*/

