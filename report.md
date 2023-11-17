# 2D Gaussian Quadrature
00957016 高敬庭
## Result
+ Exact value = 470.327210063638  
![Alt text](assets/photos/image.png)  
+ 1x1 with different sample points  
![Alt text](assets/photos/image-1.png)![Alt text](assets/photos/image-7.png)  
+ 2x2 with different sample points  
![Alt text](assets/photos/image-4.png)![](assets/photos/image-3.png)  
+ 4x4 with different sample points  
![Alt text](assets/photos/image-6.png)![Alt text](assets/photos/image-5.png)  
+ 8x8 with different sample points  
![Alt text](assets/photos/image-8.png)![Alt text](assets/photos/image-2.png)  
根據上述結果可以看到在domain相同的情況下，增加sample point是可以提高精準度，但是同樣數量的sample point，將domain分的更細則不一定會更準確，少部分情況反而會比前一次誤差更大。  
  
根據以上結論再測試  
+ sample point = 2, mesh 從 1x1 ~ 8x8  
![Alt text](assets/photos/image-9.png)![Alt text](assets/photos/image-10.png)  
+ sample point = 4, mesh 從 1x1 ~ 8x8  
![Alt text](assets/photos/image-12.png)![Alt text](assets/photos/image-11.png)  
可以看到細分domain不一定會更準，但是夠多的sample point和足夠細的domain可以求出精準的結果。