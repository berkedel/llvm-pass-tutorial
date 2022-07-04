#ifndef _STRING_ENCRYPTION_H_
#define _STRING_ENCRYPTION_H_
#include "llvm/Pass.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/PassRegistry.h"
#if LLVM_VERSION_MAJOR >= 13
#include "llvm/Passes/PassBuilder.h"
#endif
using namespace std;
using namespace llvm;

// Namespace
namespace llvm {
	ModulePass* createStringEncryptionPass();
	ModulePass* createStringEncryptionPass(bool flag);
	void initializeStringEncryptionPass(PassRegistry &Registry);
#if LLVM_VERSION_MAJOR >= 13
	class StringEncryptionPass : public PassInfoMixin<StringEncryptionPass>{ 
        public:
            PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);
            static bool isRequired() { return true; }
	};
#endif
}
#endif
