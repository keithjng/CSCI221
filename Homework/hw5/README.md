# Estimation of pi

This program was created in response to homework 5 of Reed College's CSCI 221 course. It is designed to estimate the value of pi based on the number of grid points entered by the user. It is the work of Keith Ng.

## Results

During my tests, I received the following estimations of pi:
```
n = 10 grid points: 3.16
n = 100 grid points: 3.1372
n = 1000 grid points: 3.14139
n = 10000 grid points: 3.14159
```

## Run times

My program has a complexity of O(n^2), since it utilizes a double loop.

This is how long it took to run the program given different values of gridpoints:
(Don't worry, for these tests, I changed my code so that it did not take an input, otherwise the timing would have been affected by the user)
```
n = 10 grid points: 0.007 seconds
n = 100 grid points: 0.007 seconds
n = 1000 grid points: 0.009 seconds
```

## Adding constexpr

After adding constexpr to the beginning of my function and fixing the code, I got the results and run times of:
```
n = 10 grid points: 3.16
n = 100 grid points: 3.1372
n = 1000 grid points: 3.14139
```

```
n = 10 grid points: 0.005 seconds
n = 100 grid points: 0.005 seconds
n = 1000 grid points: 0.007 seconds
```

Using constexpr did not change my results of pi, the same values of n still resulted in the same estimate for pi. However, it does seem that using constexpr sped up my run time by just a little bit, though the differences are rather small.

Another thing I noticed (though may not be significant) is that in the original version of the function, the "user" category was less than the "system" category, meaning that aspect took less time. However, in the constexpr version, the "system" category became less than the "user" category. Does this imply that constexpr speeds up the system but does not change the user speed?
