#include <stdio.h>

#include <stdint.h>

#include <stdbool.h>

#define BLOCK_SIZE 8192    

#define POINTER_SIZE 4     

#define TOTAL_BLOCKS 4096   

bool isBlockFree(uint32_t block) 

{
    return true;
}
void allocateBlocks(uint32_t* blocks, uint32_t numBlocks) 
{
    printf("Allocating %u blocks to the file.\n", numBlocks);
}
uint64_t calculateMaxFileSize() 
{
    uint64_t maxFileSize = 0;
    uint64_t directBlocks = 12;                         
    uint64_t singleIndirectBlocks = BLOCK_SIZE / POINTER_SIZE;    
    uint64_t doubleIndirectBlocks = singleIndirectBlocks * singleIndirectBlocks; 
    uint64_t tripleIndirectBlocks = singleIndirectBlocks * doubleIndirectBlocks; 
    maxFileSize = directBlocks + singleIndirectBlocks + doubleIndirectBlocks + tripleIndirectBlocks;
    maxFileSize *= BLOCK_SIZE;
    return maxFileSize;
}
uint32_t findNextContiguousBlocks(uint32_t startBlock, uint32_t numBlocks) 
{
    uint32_t currentBlock = startBlock;
    while (currentBlock < TOTAL_BLOCKS && numBlocks > 0) 

	{        if (!isBlockFree(currentBlock)) 

		{
            numBlocks = 0;
        } else 
		{
            numBlocks--;
        }
        currentBlock++;
    }
    if (numBlocks == 0) 
	{
        return currentBlock - startBlock;
    }
    return 0;
}
int main() 
{
    uint64_t maxFileSize = calculateMaxFileSize();
    printf("Maximum size of a file that can be stored in the given file system: %llu bytes\n", maxFileSize);
    uint32_t startBlock = 100;    
    uint32_t numBlocks = 5;       
    uint32_t contiguousBlocks = findNextContiguousBlocks(startBlock, numBlocks);
    if (contiguousBlocks > 0) 
	{
        printf("Next available contiguous blocks: Start Block: %u, Number of Blocks: %u\n", startBlock, contiguousBlocks);
        allocateBlocks(&startBlock, numBlocks);
    } else 
	{
        printf("No available contiguous blocks found.\n");
    }
    return 0;
}
