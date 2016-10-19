//
//  things.cpp
//  Program4
//
//  Created by Gregory Asher on 2/22/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//

#include <stdio.h>
using namespace std;
void BottomUpMergesort(int[] a)
{
    int[] temp = new int[a.Length];
    for (int runWidth = 1; runWidth < a.Length; runWidth = 2 * runWidth){
        for (int eachRunStart = 0; eachRunStart < a.Length; eachRunStart = eachRunStart + 2 * runWidth){
            int start = eachRunStart;
            int mid = eachRunStart + (runWidth - 1);
            if(mid >= a.Length)
            {
                mid = a.Length - 1;
            }
            int end = eachRunStart + ((2 * runWidth) - 1);
            if(end >= a.Length)
            {
                end = a.Length - 1;
            }
            
            this.Merge(a, start, mid, end, temp);
        }
        for (int i = 0; i < a.Length; i++)
        {
            a[i] = temp[i];
        }
    }
    void Merge(int[] a, int start, int mid, int end, int[] temp)
    {
        int i = start, j = mid+1, k = start;
        while((i<=mid) && (j<=end))
        {
            if(a[i] <= a[j])
            {
                temp[k] = a[i];
                i++;
            }
            else
            {
                temp[k] = a[j];
                j++;
            }
            k++;
        }
        while(i<=mid)
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        while (j <= end)
        {
            temp[k] = a[j];
            j++;
            k++;
        }
        Assert.IsTrue(k == end+1);
        Assert.IsTrue(i == mid+1);
        Assert.IsTrue(j == end+1);
    }
    
}