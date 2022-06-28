#ifndef _INDIRECT_BRANCH_H_
#define _INDIRECT_BRANCH_H_
#include "llvm/Pass.h"
#include "llvm/IR/LegacyPassManager.h"
using namespace std;
using namespace llvm;

// Namespace
namespace llvm {
	FunctionPass* createIndirectBranchPass();
	FunctionPass* createIndirectBranchPass(bool flag);
	void initializeIndirectBranchPass(PassRegistry &Registry);
#if LLVM_VERSION_MAJOR >= 13
	class IndirectBranchPass : public PassInfoMixin<IndirectBranchPass>{ 
        public:
            PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);
            static bool isRequired() { return true; }
	};
#endif
}
#endif
