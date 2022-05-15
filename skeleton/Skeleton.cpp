#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {
  struct SkeletonPass : public FunctionPass {
    static char ID;
    SkeletonPass() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
      errs() << "I saw a function called " << F.getName() << "!\n";
      return false;
    }
  };
}

char SkeletonPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerSkeletonPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new SkeletonPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerSkeletonPass);

#if LLVM_VERSION_MAJOR >= 13

struct NewSkeletonPass : PassInfoMixin<NewSkeletonPass> {
public:
    static bool isRequired() {
        errs() << "isRequired invoked\n";
        return true;
    }

    static PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        errs() << "Module name is " << M.getName() << "!\n";
        return PreservedAnalyses::all();
    }
};

void myCallback(llvm::ModulePassManager &PM, llvm::PassBuilder::OptimizationLevel Level) {
    PM.addPass(NewSkeletonPass());
}

/* New PM Registration */
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
    errs() << "llvmGetPassPluginInfo\n";
    return {LLVM_PLUGIN_API_VERSION,
            "skeleton",
            LLVM_VERSION_STRING,
            [](PassBuilder &PB) {
                PB.registerPipelineStartEPCallback(myCallback);
                // TODO: handle opt
                // PB.registerPipelineParsingCallback
            }};
}
#endif