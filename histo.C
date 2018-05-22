#include "TH1.h"
#include "TH2.h"
#include <string>
#include "TCanvas.h"
#include <TLegend.h>

void histo () {

/*///////////////подключение//////////////////////////////////////////
    gSystem->Load("libMathMore");
    gROOT->LoadMacro("runglauber_v3.0.C+");
///////////////генерация деревьев/////////////////////////////////////
    runAndSaveNtuple(100000,"Pb","Pb",20.0,-1,0.6,-1,-1,"open1.root");
    runAndSaveNtuple(100000,"Pb","Pb",34.0,-1,0.6,-1,-1,"open2.root");
    runAndSaveNtuple(100000,"Pb","Pb",41.6,-1,0.6,-1,-1,"open3.root");
    runAndSaveNtuple(100000,"Pb","Pb",61.8,-1,0.6,-1,-1,"open4.root");
/*////////////////////////////////////////////////////////////////////

    Float_t Npart,Ncoll,B,Ecc2,Ecc3;
    std::string fileName = "open";
    std::string fileType = ".root";
    char buff[2];

    TCanvas *canva1 = new TCanvas("canvas1", "Distribution of the number of participating nucleons");
    TCanvas *canva2 = new TCanvas("canvas2", "Distribution of the number of binary collisions");
    TCanvas *canva3 = new TCanvas("canvas3", "Distribution of impact parameter");
    TCanvas *canva4 = new TCanvas("canvas4", "Correlation between 'Npart' and 'Ncoll'");
    TCanvas *canva5 = new TCanvas("canvas5", " Correlation between 'Npart' and 'B'");
    TCanvas *canva6 = new TCanvas("canvas6", "Correlation between 'Ncoll' and 'B'");
    TCanvas *canva7 = new TCanvas("canvas7", "Eccentricity versus 'Npart'");
    TCanvas *canva8 = new TCanvas("canvas8", "Eccentricity (2) versus 'Npart'");
    TLegend *pLegend = new TLegend(0.9, 0.9, .75, .75);
 
    for(Int_t z=1; z<5; z++){

	sprintf(buff, "%i", z);
    	TFile *f = new TFile((fileName + buff + fileType).c_str());
     	TTree *t =(TTree*)f->Get("nt_Pb_Pb");

     	t->SetBranchAddress("Npart",&Npart);
     	t->SetBranchAddress("Ncoll",&Ncoll); 
     	t->SetBranchAddress("B",&B);
     	t->SetBranchAddress("Ecc2",&Ecc2); 
     	t->SetBranchAddress("Ecc3",&Ecc3);   

	TH1F  *h1  =  new  TH1F("h1","Distribution of the number of participating nucleons",  100,  0, 450);
	TH1F  *h2  =  new  TH1F("h2","Distribution of the number of binary collisions",  200,  0, 2100);
	TH1F  *h3  =  new  TH1F("h3","Distribution of impact parameter",  100,  0, 20);
	TH2F  *h4  =  new  TH2F("h4","Correlation between 'Npart' and 'Ncoll'",  100,  0, 450, 200, 0, 2100);
	TH2F  *h5  =  new  TH2F("h5"," Correlation between 'Npart' and 'B'",  100,  0, 20, 100, 0, 450);	
	TH2F  *h6  =  new  TH2F("h6","Correlation between 'Ncoll' and 'B'",  100,  0, 20, 100, 0, 2100);
	TH2F  *h7  =  new  TH2F("h7","Eccentricity versus 'Npart'",  100,  0, 450, 100, 0, 1);
	TH2F  *h8  =  new  TH2F("h8","Eccentricity(2) versus 'Npart'",  100,  0, 450, 100, 0, 1);
    
     	Int_t nentries = (Int_t)t->GetEntries();
     	for (Int_t i=0; i<nentries; i++) {
          	t->GetEntry(i);
         	h1->Fill(Npart);
		h2->Fill(Ncoll);
		h3->Fill(B);
		h4->Fill(Npart,Ncoll);
		h5->Fill(B,Npart);
		h6->Fill(B,Ncoll);
		h7->Fill(Npart,Ecc2);
		h8->Fill(Npart,Ecc3);
   	}

        if(z==1){pLegend->AddEntry(h1, "5 Gev" , "l");}
        if(z==2){pLegend->AddEntry(h2, "40 Gev" , "l");}
        if(z==3){pLegend->AddEntry(h3, "200 Gev" , "l");}
        if(z==4){pLegend->AddEntry(h4, "2760 Gev" , "l");}

	canva1->cd();
        canva1->SetLogy();
        h1->SetStats(0);
        h1->GetXaxis()->SetTitle("Npart(N)");  
        h1->GetYaxis()->SetTitle("Events(N)");
    	h1->SetLineColor(z);
    	h1->Draw("same");

	canva2->cd();
        canva2->SetLogy();
        h2->SetStats(0);
        h2->GetXaxis()->SetTitle("Ncoll(N)");  
        h2->GetYaxis()->SetTitle("Events(N)");
    	h2->SetLineColor(z);
    	h2->Draw("same");

	canva3->cd();
        h3->SetStats(0); 
        h3->GetXaxis()->SetTitle("b[fm]"); 
        h3->GetYaxis()->SetTitle("Events(N)");
    	h3->SetLineColor(z);
    	h3->Draw("same");

	canva4->cd();
        h4->ProfileX()->SetStats(0);
        h4->GetXaxis()->SetTitle("Npart(N)"); 
        h4->ProfileX()->GetYaxis()->SetTitle("Ncoll(N)");
    	h4->SetLineColor(z);
        if(z==1){h4->ProfileX()->DrawClone("same");}
        h4->ProfileX()->DrawClone("same");

	canva5->cd();
        h5->ProfileX()->SetStats(0);
        h5->GetXaxis()->SetTitle("b[fm]"); 
        h5->ProfileX()->GetYaxis()->SetTitle("Npart(N)");
    	h5->SetLineColor(z);
        if(z==1){h5->ProfileX()->DrawClone("same");}
        h5->ProfileX()->DrawClone("same");

	canva6->cd();
        //canva6->SetLogy();
        h6->ProfileX()->SetStats(0);
        h6->GetXaxis()->SetTitle("b[fm]"); 
        h6->ProfileX()->GetYaxis()->SetTitle("Ncoll(N)");
    	h6->SetLineColor(z);
        if(z==1){h6->ProfileX()->DrawClone("same");}
        h6->ProfileX()->DrawClone("same");

	canva7->cd();
        h7->ProfileX()->SetStats(0);
        h7->GetXaxis()->SetTitle("Npart"); 
        h7->ProfileX()->GetYaxis()->SetTitle("Ecc2");
    	h7->SetLineColor(z);
        if(z==1){h7->ProfileX()->DrawClone("same");}
        h7->ProfileX()->DrawClone("same");

	canva8->cd();
        h8->ProfileX()->SetStats(0);
        h8->GetXaxis()->SetTitle("Npart"); 
        h8->ProfileX()->GetYaxis()->SetTitle("Ecc3");
    	h8->SetLineColor(z);
        if(z==1){h8->ProfileX()->DrawClone("same");}
        h8->ProfileX()->DrawClone("same");

    }

   canva1->cd();pLegend->Draw();
   canva2->cd();pLegend->Draw();
   canva3->cd();pLegend->Draw();
   canva4->cd();pLegend->Draw();
   canva5->cd();pLegend->Draw();
   canva6->cd();pLegend->Draw();
   canva7->cd();pLegend->Draw();
   canva8->cd();pLegend->Draw();

   canva1->Print("a1.png");
   canva2->Print("a2.png");
   canva3->Print("a3.png");
   canva4->Print("a4.png");
   canva5->Print("a5.png");
   canva6->Print("a6.png");
   canva7->Print("a7.png");
   canva8->Print("a8.png");

}
