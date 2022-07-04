#ifndef _FUNCTION_WRAPPER_H_
#define _FUNCTION_WRAPPER_H_
#include "llvm/Pass.h"
#if LLVM_VERSION_MAJOR >= 13
#include "llvm/Passes/PassBuilder.h"
#endif
using namespace std;
using namespace llvm;

// Namespace
namespace llvm {
	ModulePass* createFunctionWrapperPass();
	ModulePass* createFunctionWrapperPass(bool flag);
	void initializeFunctionWrapperPass(PassRegistry &Registry);
#if LLVM_VERSION_MAJOR >= 13
	class FunctionWrapperPass : public PassInfoMixin<FunctionWrapperPass>{ 
        public:
            PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);
            static bool isRequired() { return true; }
	};
#endif
}
#endif
