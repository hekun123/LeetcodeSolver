#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition for an interval.
struct Interval {
    int start;
   int end;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    int i, start, end, startFlag, endFlag;
    int found = 0;
    for(i = 0 ; i < intervalsSize ; i ++){
        start = i;
        if((intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end)){
            startFlag = 1;
            found = 1;
            break;
        }else if(newInterval.start < intervals[i].start){
            startFlag = 0;
            found = 1;
            break;
        }
    }
    if(!found){
        start = intervalsSize;
        startFlag = 0;
    }
    //printf("%d,%d\n", start , startFlag);
    found = 0;
    for(i = 0 ; i < intervalsSize ; i ++){
        end = i;
        if(intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end){
           //|| (intervals[i].start == newInterval.end)){
            endFlag = 1;
            found = 1;
            break;
       }else if(newInterval.end < intervals[i].start){
            endFlag = 0;
            found = 1;
            break;
       }
    }
    if(!found){
        end = intervalsSize;
        endFlag = 0;
    }
    //printf("start:(%d,%d),end:(%d,%d)\n",start, startFlag, end, endFlag);
    int newFlag = 0, cnt = 0;
    int newIntervalsSize = 0;
    struct Interval *returnAns = NULL;
    struct Interval *returnAnsPtr = NULL;
    if(start == end && startFlag == 0 && endFlag == 0){
        newIntervalsSize = intervalsSize+1;
        returnAns = (struct Interval *)malloc(sizeof(struct Interval)*newIntervalsSize);
        found = 0;
        for(i = 0 ; i < intervalsSize; i ++){
            if(start == i){
                returnAns[cnt].start = newInterval.start;
                returnAns[cnt].end = newInterval.end;
                cnt ++;
                found = 1;
            }
            returnAns[cnt].start = intervals[i].start;
            returnAns[cnt].end = intervals[i].end;
            cnt ++;
        }
        if(!found){
            returnAns[cnt].start = newInterval.start;
            returnAns[cnt].end = newInterval.end;
            cnt ++;
        }
    }else{
        found = 0;
        for(i = 0 ; i < intervalsSize ; i ++){
            if(i == start){
                returnAns = (struct Interval *)realloc(returnAns, sizeof(struct Interval)*(cnt+1));
                if(newInterval.start < intervals[i].start){
                    returnAns[cnt].start = newInterval.start;
                }else{
                    returnAns[cnt].start = intervals[i].start;
                }
                found = 1;
            }
            if(i == end){
                if(endFlag == 0){
                    returnAns[cnt].end = newInterval.end;
                }else{
                    returnAns[cnt].end = intervals[i].end;
                }
                found = 0;
                cnt ++;
                if(endFlag)
                    continue;
            }
            if(!found){
                returnAns = (struct Interval *)realloc(returnAns, sizeof(struct Interval)*(cnt+1));
                returnAns[cnt].start = intervals[i].start;
                returnAns[cnt].end = intervals[i].end;
                cnt ++;
            }
        }
        if(found){
            returnAns[cnt].end = newInterval.end;
            cnt ++;
        }
    }
    (*returnSize) = cnt;
    return returnAns;
}

int main()
{
    struct Interval intervals[]{
       {-1,2},{3,5},{6,7},{8,10},{12,16}
    };
    struct Interval newInter = {-2,-1};
    int cnt;
    struct Interval* ans = insert(intervals, 5, newInter, &cnt);
    for(int i = 0 ; i < cnt ; i ++){
        printf("{%d,%d},", ans[i].start, ans[i].end);
    }
    return 0;
}
