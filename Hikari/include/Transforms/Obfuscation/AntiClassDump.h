#ifndef _ANTI_CLASSDUMP_H_
#define _ANTI_CLASSDUMP_H_
#include "llvm/Pass.h"
#include "llvm/IR/LegacyPassManager.h"
#if LLVM_VERSION_MAJOR >= 13
#include "llvm/Passes/PassBuilder.h"
#endif
using namespace std;
using namespace llvm;

// Namespace
namespace llvm {
	ModulePass* createAntiClassDumpPass();
	void initializeAntiClassDumpPass(PassRegistry &Registry);
#if LLVM_VERSION_MAJOR >= 13
	class AntiClassDumpPass : public PassInfoMixin<AntiClassDumpPass>{ 
        public:
            PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);
            static bool isRequired() { return true; }
	};
#endif
}
#endif
