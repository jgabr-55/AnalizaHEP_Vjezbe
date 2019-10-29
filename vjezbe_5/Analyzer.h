//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct 29 10:29:06 2019 by ROOT version 6.18/04
// from TTree T/stablo
// found on file: Analysis.root
//////////////////////////////////////////////////////////

#ifndef Analyzer_h
#define Analyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>


// Header file for the classes stored in the TTree if any.
#include <string>
#include <iostream>

using namespace std;

class Analyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           EventNumber;
   string          *Particle1name;
   Int_t           Particle1isBoson;
   Double_t        Particle1mass;
   Double_t        Particle1px;
   Double_t        Particle1py;
   Double_t        Particle1pz;
   Double_t        Particle1E;
   Double_t        Particle1pt;
   string          *Particle2name;
   Int_t           Particle2isBoson;
   Double_t        Particle2mass;
   Double_t        Particle2px;
   Double_t        Particle2py;
   Double_t        Particle2pz;
   Double_t        Particle2E;
   Double_t        Particle2pt;

   // List of branches
   TBranch        *b__EventNumber;   //!
   TBranch        *b_Particle1name;   //!
   TBranch        *b__DecayParticle1_isBoson;   //!
   TBranch        *b__DecayParticle1_mass;   //!
   TBranch        *b__DecayParticle1_px;   //!
   TBranch        *b__DecayParticle1_py;   //!
   TBranch        *b__DecayParticle1_pz;   //!
   TBranch        *b__DecayParticle1_E;   //!
   TBranch        *b__DecayParticle1_pt;   //!
   TBranch        *b_Particle2name;   //!
   TBranch        *b__DecayParticle2_isBoson;   //!
   TBranch        *b__DecayParticle2_mass;   //!
   TBranch        *b__DecayParticle2_px;   //!
   TBranch        *b__DecayParticle2_py;   //!
   TBranch        *b__DecayParticle2_pz;   //!
   TBranch        *b__DecayParticle2_E;   //!
   TBranch        *b__DecayParticle2_pt;   //!

   Analyzer(TTree *tree=0);
   virtual ~Analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Analyzer_cxx
Analyzer::Analyzer(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Analysis.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Analysis.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

Analyzer::~Analyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}


Int_t Analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Analyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Analyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Particle1name = 0;
   Particle2name = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventNumber", &EventNumber, &b__EventNumber);
   fChain->SetBranchAddress("Particle1name", &Particle1name, &b_Particle1name);
   fChain->SetBranchAddress("Particle1isBoson", &Particle1isBoson, &b__DecayParticle1_isBoson);
   fChain->SetBranchAddress("Particle1mass", &Particle1mass, &b__DecayParticle1_mass);
   fChain->SetBranchAddress("Particle1px", &Particle1px, &b__DecayParticle1_px);
   fChain->SetBranchAddress("Particle1py", &Particle1py, &b__DecayParticle1_py);
   fChain->SetBranchAddress("Particle1pz", &Particle1pz, &b__DecayParticle1_pz);
   fChain->SetBranchAddress("Particle1E", &Particle1E, &b__DecayParticle1_E);
   fChain->SetBranchAddress("Particle1pt", &Particle1pt, &b__DecayParticle1_pt);
   fChain->SetBranchAddress("Particle2name", &Particle2name, &b_Particle2name);
   fChain->SetBranchAddress("Particle2isBoson", &Particle2isBoson, &b__DecayParticle2_isBoson);
   fChain->SetBranchAddress("Particle2mass", &Particle2mass, &b__DecayParticle2_mass);
   fChain->SetBranchAddress("Particle2px", &Particle2px, &b__DecayParticle2_px);
   fChain->SetBranchAddress("Particle2py", &Particle2py, &b__DecayParticle2_py);
   fChain->SetBranchAddress("Particle2pz", &Particle2pz, &b__DecayParticle2_pz);
   fChain->SetBranchAddress("Particle2E", &Particle2E, &b__DecayParticle2_E);
   fChain->SetBranchAddress("Particle2pt", &Particle2pt, &b__DecayParticle2_pt);
   Notify();
}

Bool_t Analyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Analyzer_cxx
