#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>&v,int left, int right, int mid)
{
	    int id1 = left;
	        int id2 = mid + 1; 
		    int k = 0;
		        vector<int> temp(right - left + 1,0);
			    while(id1 <= mid && id2 <= right)
				        {
						        if(a[id1] < a[id2])
								        {
										            temp[k++] = a[id1++];
											            }
												            else
														            {
																                temp[k++] = a[id2++];
																		        }
																			    }
																			        while(id1 <= mid)
																					    {
																						            temp[k++] = a[id1++];
																							        }
																								    while(id2 <= right)
																									        {
																											        temp[k++] = a[id2++];
																												    }
																												        for(int i = left, k = 0; i <= right; i++,k++)
																														    {
																															            v[i] = temp[k];
																																        }
}

void MergeSort(std::vector<int>&v,int left,int right)
{
	    if(left >= right) return;
	        int mid = (left + right) / 2;
		    MergeSort(a,left,mid);
		        MergeSort(a,mid+1,right);
			    Merge(a,left,right,mid);
}
