//===- SubstitutionIncludes.h - Substitution Obfuscation pass-------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains includes and defines for the substitution pass
//
//===----------------------------------------------------------------------===//

#ifndef _SUBSTITUTIONS_H_
#define _SUBSTITUTIONS_H_


// LLVM include
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "Transforms/Obfuscation/CryptoUtils.h"
#if LLVM_VERSION_MAJOR >= 13
#include "llvm/Passes/PassBuilder.h"
#endif

// Namespace
using namespace llvm;
using namespace std;

namespace llvm {
	FunctionPass *createSubstitutionPass();
	FunctionPass *createSubstitutionPass(bool flag);
	void initializeSubstitutionPass(PassRegistry &Registry);
#if LLVM_VERSION_MAJOR >= 13
	class SubstitutionPass : public PassInfoMixin<SubstitutionPass>{ 
        public:
            PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
            static bool isRequired() { return true; }
    };
#endif
}

#endif
