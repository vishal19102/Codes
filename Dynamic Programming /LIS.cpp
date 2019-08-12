#include<bits/stdc++.h>

using namespace  std; 

int LIS(int *arr,int n ){

	int *output=new int[n];
	int ans;
	output[0]=1;

	for(int i=0;i<n;i++)
	{
		output[i]=1;
		for(int j=i-1;j>=0;j--)
				{
					if(arr[j]>arr[i])
						continue;
					else
						{
							int temp=output[j]+1;
							if(temp>output[i])
									output[i]=temp;

						}
				}
	}
	ans=output[0];
	for(int i=1;i<n;i++)
	{
		if(ans<output[i])
			ans=output[i];
	}
	delete[] output;

	return ans;

}

int main(){


	int n;
	cin>>n;
	int *arr= new int[n];
	//int *output=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int ans =LIS(arr,n);
	cout<<"ans is  "<<ans<<endl;
	delete[] arr;
	return 0;
}