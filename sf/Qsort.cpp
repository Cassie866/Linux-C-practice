int Partition1(int array[], int left, int right)
{
	       int begin = left;     
	              int end = right;
		             while (begin < end)
				            {
						                  while (begin < end && array[begin] <= array[right])
									                {
												                     begin++;
														                   }
																                 while (begin < end && array[end] >= array[right])
																			               {
																					                            end--;
																								                  }
																										                Swap(array + begin, array + end);
																												       }
																												              Swap(array + begin, array + right);
																													             return begin;
}


int Partition2(int array[], int left, int right)
{
	       int begin = left;
	              int end = right;
		             int pivot = array[right];
			            while (begin < end)
					           {
							                 while (begin < end && array[begin] <= pivot)
										               {
												                            begin++;
															                  }
																	                array[end] = array[begin];
																			              while (begin < end && array[end] >= pivot)
																					                    {
																								                         end--;
																											               }
																												                     array[begin] = array[end];
																														            }
																															           array[begin] = pivot;
																																          return begin;
}


int Partition3(int array[], int left, int right)
{
	       int d = left;
	              for (int i = left; i < right; i++)
			             {
					                   if (array[i] < array[right])
								                 {
											                      Swap(array + i, array + d);
													                           d++;
																                 }
																		        }
																			       Swap(array + d, array + right);
																			              return d;
}


void QuickSort(int array[], int left, int right)
{
	       if (left >= right)
		              {
				                    return;
						           }
							          int div;   
								         div = Partition1(array, left, right);
									        //div = Partition2(array, left, right);     
										       //div = Partition3(array, left, right);     
										              QuickSort(array, left, div - 1);
											             QuickSort(array, div + 1, right);
}

