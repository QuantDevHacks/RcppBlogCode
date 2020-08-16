# This file is *not* part of the package.
# It resides in an outside directory and is used
# to test the RcppBlogCode package.


library(RcppBlogCode)

##### Simple Examples #####
## Example 1:
# Now, we can call our simple vecSum(.) 
# function via the rcppVecSum interface function:
rAdd(531, 9226)     # 9757

## Example 2:
# Similarly, call sortVec(.) via rcppSortVec(.):
(x <- c(5:1))
rSortVec(x)

## Example 3:
rProdLcmGcd(10, 20)     # 200
##### END Simple Examples #####



#####   Class Examples   #####
## Example 5:
# These functions are exposed from C++.
# They will create instances of the Square and
# Circle classes that are defined in the separate
# ConcreteShapes.h file:
squareArea(4)
circleArea(1)

## Example 7:
# Create R vectors containing constructor parameters 
# for both the Square and Circle classes.  Then, use
# sapply in R to vectorize each area calculation.
# Finally, plot the results in R, showing that we can
# take results computed in C++, and use them in 
# R visualization tools that don't exist in C++:
squareSides <- c(1:10)
circleRadii <- c(1:10)

squareAreas <- sapply(squareSides, squareArea)
circleAreas <- sapply(circleRadii, circleArea)

### Use plotly to visualize some results:
library(plotly)
dfSq <- matrix(data=c(squareSides, squareAreas), nrow=length(squareSides), ncol=2)
dfSq <- as.data.frame(dfSq)
colnames(dfSq) = c("Side", "Area")
rownames(dfSq) = NULL
plot_ly(dfSq, x = ~Side, y = ~ Area, type = "bar") %>% 
  layout(title="Areas of Squares")


dfCirc <- matrix(data=c(circleRadii, circleAreas), nrow=length(squareSides), ncol=2)
dfCirc <- as.data.frame(dfCirc)
colnames(dfCirc) = c("Radius", "Area")
rownames(dfCirc) = NULL
plot_ly(dfCirc, x = ~Radius, y = ~ Area, type = 'scatter', 
        mode = 'lines', color = 'red') %>%
  layout(title="Areas of Circles")

