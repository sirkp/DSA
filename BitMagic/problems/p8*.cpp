// https://practice.geeksforgeeks.org/problems/gray-code-1587115620/1/?track=SPCF-BitMagic&batchId=154
// Binary to Gray
// 1)The Most Significant Bit (MSB) of the gray code is always equal to the MSB of the given binary code.
// 2)Other bits of the output gray code can be obtained by XORing binary code bit at that index and previous index.
int greyConverter(int n){
    return (n^(n>>1));
}