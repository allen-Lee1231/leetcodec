//#include <stdio.h>
//
//
//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
//    // assume nums1 and nums2 cannot be both empty.
//    if (nums1Size == 0) return (nums2Size & 1)?nums2[nums2Size / 2]:(nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2.0;
//    if (nums2Size == 0) return (nums1Size & 1)?nums1[nums1Size / 2]:(nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2.0;
//
//    int togo = (nums1Size + nums2Size - 1) / 2;
//    if (togo == 0) return (nums1[0] + nums2[0]) / 2.0;
//    int left1 = 0, left2 = 0, flag, p1 = 0, p2 = 0;
//    while (togo > 1){
//        flag = togo / 2, p1 = flag + left1, p2 = flag + left2;
//        if (p1 > nums1Size - 1) p2 += p1 - nums1Size + 1, p1 = nums1Size - 1;
//        if (p2 > nums2Size - 1) p1 += p2 - nums2Size + 1, p2 = nums2Size - 1;
//
//        if (nums1[p1] > nums2[p2]){
//            if (left2 == p2){
//                left1 += --togo;
//                togo = 1;
//                break;
//            }
//            togo -= p2 - left2;
//            left2 += p2 - left2;
//        }
//        else if (nums1[p1] < nums2[p2]){
//            if (left1 == p1){
//                left2 += --togo;
//                togo = 1;
//                break;
//            }
//            togo -= p1 - left1;
//            left1 += p1 - left1;
//        }
//        else {
//            togo -= p1 - left1;
//            togo -= p2 - left2;
//            left1 = p1, left2 = p2;
//            break;
//        }
//    }
//
//    int i11, i12, i21, i22;
//    (left1 < (nums1Size - 1))? (i11 = nums1[left1 + 1]): (i11 = nums1[left1]);
//    (left2 < (nums2Size - 1))? (i21 = nums2[left2 + 1]): (i21 = nums2[left2]);
//    (left1 < (nums1Size - 2))? (i12 = nums1[left1 + 2]): (i12 = i11);
//    (left2 < (nums2Size - 2))? (i22 = nums2[left2 + 2]): (i22 = i21);
//    if (togo == 1 && (nums1Size + nums2Size)&1){   //odd
//        if (nums1[left1] < nums2[left2]){
//            if (left1 >= nums1Size - 1) return nums2[left2];
//            else return (nums1[left1 + 1] < nums2[left2])? nums1[left1 + 1]: nums2[left2];
//        }
//        else if (left2 >= nums2Size - 1) return nums1[left1];
//        else return (nums1[left1] < nums2[left2 + 1])? nums1[left1]: nums2[left2 + 1];
//    }
//
//    if (togo == 1 && ((nums1Size + nums2Size)&1) == 0){  //even
//        if (nums1[left1] < nums2[left2]){
//            if (left2<(nums2Size-1) && ((i11>nums2[left2] && i11>i21) || (left1==nums1Size-1 && nums1[left1]<i21))) return (i21+nums2[left2])/2.0;
//            else if (left1 < (nums1Size - 2) && nums2[left2] > i11 && nums2[left2] > i12) return (i11 + i12) / 2.0;
//            else return (i11 + nums2[left2]) / 2.0;
//        }
//        else if (left2 < (nums2Size - 2) && nums1[left1] > i21 && nums1[left1] > i22) return (i21 + i22) / 2.0;
//        else if (left1<(nums1Size-1) && ((i21>nums1[left1] && i21>i11) || (left2==nums2Size-1 && nums2[left2]<i11))) return (i11+nums1[left1])/2.0;
//        else return (i21 + nums1[left1]) / 2.0;
//    }
//
//    if ((nums1Size+nums2Size)&1) return (nums1[left1] < nums2[left2]? nums1[left1]: nums2[left2]);
//    else if (nums1[left1] > nums2[left2] && nums1[left1] > i21) return (nums2[left2] + i21) / 2.0;
//    else if (nums2[left2] > nums1[left1] && nums2[left2] > i11) return (nums1[left1] + i11) / 2.0;
//    else return (nums1[left1] + nums2[left2]) / 2.0;
//}
//
//
//int main()
//{
//    int ary1[4] = {1, 2, 3, 4};
//    int ary2[4] = {2, 3, 5, 6};
//    printf("The median is %d\n", findMedianSortedArrays(ary1, 4, ary2, 4));
//    getchar();
//    return 0;
//}