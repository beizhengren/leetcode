//
// Created by wyz on 20-11-17.
//

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(int* arr, int n){
    bool isSorted = true;
    for(int i = n - 1; i >= 1; --i){
        for(int j = 0; j < i; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSorted = false;
            }
        }
        if(isSorted == true){break;}
    }
}

int median3(int* arr, int l, int r){
    int& v1 = arr[l];
    int& v3 = arr[r];
    //如果用">>"必须加"()", 因为运算符的顺序影响
    int idx = l + ((r - l) / 2);
    int& v2 = arr[idx];
    if(v1 > v2){ swap(v1, v2);}
    if(v1 > v3){ swap(v1, v3);}
    if(v2 > v3){ swap(v2, v3);}

    return idx;
}


int median3_opt(int* arr, int l, int r){
    int& v1 = arr[l];
    int& v3 = arr[r];
    //如果用">>"必须加"()", 因为运算符的顺序影响
    int idx = l + ((r - l) / 2);
    int& v2 = arr[idx];
    if(v1 > v2){ swap(v1, v2);}
    if(v1 > v3){ swap(v1, v3);}
    if(v2 > v3){ swap(v2, v3);}

    swap(v2, arr[r-1]);
    return r-1;
}

//挖坑法
void quick_sort_v1(int* arr, int l, int r){
    if(l >= r) return;
    int x = l;
    int y = r;
    int pivot = arr[l];

    while(x < y){
        while(x < y && arr[y] > pivot){ --y;}
        if(x < y){ arr[x] = arr[y]; ++x;}
        while(x < y && arr[x] < pivot){ ++x;}
        if(x < y){ arr[y] = arr[x]; --y;}
    }
    arr[x] = pivot;
    quick_sort_v1(arr, l, x-1);
    quick_sort_v1(arr, x+1, r);
}

//挖坑法优化
void quick_sort_v1_opt(int* arr, int l, int r){
    if(l >= r) return;
    if(r - l + 1 > 2){
        int x = l;
        int y = r;
        int idx = median3(arr, l, r);
        int pivot = arr[idx];
        swap(arr[idx], arr[l]);

        while(x < y){
            while(x < y && arr[y] > pivot){ --y;}
            if(x < y){ arr[x] = arr[y]; ++x;}
            while(x < y && arr[x] < pivot){ ++x;}
            if(x < y){ arr[y] = arr[x]; --y;}
        }
        arr[x] = pivot;
        quick_sort_v1(arr, l, x-1);
        quick_sort_v1(arr, x+1, r);
    }else{
        bubble_sort(arr + l, r-l+1);
    }

}

//陈越法
void quick_sort_vn(int* arr, int l, int r){
    if(l >= r) return;
    int cut_off = 2;
    if(r - l + 1 > cut_off){
        int idx = median3(arr, l, r);
        int pivot = arr[idx];
        swap(arr[idx], arr[r]);
        int i = l;
        int j = r;

        while(i < j){
            while(/*i < j &&*/ arr[++i] < pivot){}
            while(/*i < j &&*/ arr[--j] > pivot){}

            if(i < j){swap(arr[i], arr[j]);}
        }
        swap(arr[i], arr[r]);
        quick_sort_vn(arr, l, i - 1);
        quick_sort_vn(arr, i + 1, r);
    }
    else{
        bubble_sort(arr+l, r - l + 1);
    }
}

void quick_sort_vn_opt(int* arr, int l, int r){
    if(l >= r) return;
    if(r - l + 1 > 2){
        int idx = median3_opt(arr, l, r);
        int pivot = arr[idx];

        int i = l;
        int j = r-1;
        while(i < j){
            while(arr[++i] < pivot){};
            while(arr[--j] > pivot){};
            if(i < j){swap(arr[i], arr[j]);}
        }
        swap(arr[i], arr[r-1]);
        quick_sort_vn_opt(arr, l, i - 1);
        quick_sort_vn_opt(arr, i + 1, r);

    }else{
        bubble_sort(arr + l, r - l + 1);
    }
}
