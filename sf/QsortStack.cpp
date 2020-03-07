#include <stack>   
void QuickSortNor(int array[], int size)
{
	       std::stack<int>　stack;
	              stack.push(size - 1);        // right
		             stack.push(0);               // left
			            while (!stack.empty())
					           {
							                 int left = stack.top(); 
									               stack.pop();
										                     int right = stack.top(); 
												                   stack.pop();
														                 if (left >= right)
																	               {
																			                            continue;
																						                  }
																								                else
																											              {
																													                           int d = Partition1(array, left, right);
																																                        // [d + 1, right]
																																			                     stack.push(right);
																																					                          stack.push(d + 1);
																																								                       // [left, d - 1]
																																										                            stack.push(d - 1);
																																													                         stack.push(left);
																																																               }
																																																	              }
}

