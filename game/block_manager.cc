#include "block_manager.h"
#include "block.h"

const int LeftPad = 96;
const int TopPad = 330;

BlockManager::BlockManager() { CreateDefaultBlocks(); }

void BlockManager::Update() {}

void BlockManager::CreateBlock(int i, int j) {
  auto block = std::make_shared<Block>();
  block->DestRect().x = i * block->Width() + LeftPad;
  block->DestRect().y = j * block->Height() + TopPad;
  blocks[i][j] = block;
  this->AddChild(block);
}

void BlockManager::CreateDefaultBlocks() {
  for (int i = 0; i < BlockMaxWidth; i++) {
    for (int j = BlockMaxWidth - 3; j < BlockMaxWidth; j++) {
      CreateBlock(i, j);
    }
  }
}
