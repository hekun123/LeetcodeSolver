#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Interval {
    int start;
    int end;
};

int cmp(const void *a, const void *b){
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if(intervalsSize <= 0){
        (*returnSize) = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(struct Interval), cmp);

    int i, cnt;
    struct Interval* nodeHead = NULL;

    cnt = 1;
    nodeHead = (struct Interval*)realloc(nodeHead, sizeof(struct Interval)*cnt);
    nodeHead->start = intervals[0].start;
    nodeHead->end   = intervals[0].end;

    for(i = 1 ; i < intervalsSize; i ++){
        if(intervals[i].start <= nodeHead[cnt-1].end){
            //merge
            if(intervals[i].end > nodeHead[cnt-1].end)
                nodeHead[cnt-1].end = intervals[i].end;
        }else{
            //new
            cnt ++;
            nodeHead = (struct Interval*)realloc(nodeHead, sizeof(struct Interval)*cnt);
            nodeHead[cnt-1].start = intervals[i].start;
            nodeHead[cnt-1].end = intervals[i].end;
        }
    }
    (*returnSize) = cnt;
    return nodeHead;
}
int main()
{
    struct Interval intervals[]{
        {1,4}
    };
    int cnt;
    struct Interval* ans = merge(intervals, 1, &cnt);
    for(int i = 0 ; i < cnt ; i ++){
        printf("{%d,%d}\n", ans[i].start, ans[i].end);
    }
    return 0;
}
