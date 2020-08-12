#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>

#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(int, char *[])
{
  // Create a table with some points in it
  // table is a pointer of type vtKtable 
  //
  auto  number_of_functions  = 3;
  vector<string>  functions_names{"exp(a)","exp(-a)","exp(2a)"};
  
  
  

  vtkSmartPointer<vtkTable> table1 = vtkSmartPointer<vtkTable>::New();
  vtkSmartPointer<vtkFloatArray> * functions=  new vtkSmartPointer<vtkFloatArray>[number_of_functions];
  vtkSmartPointer<vtkFloatArray> arrX1 = vtkSmartPointer<vtkFloatArray>::New();
  arrX1->SetName("X Axis"); // we can name the array
  table1->AddColumn(arrX1);

  for (int i = 0 ; i < number_of_functions ; ++i)
  {
    functions[i] = vtkSmartPointer<vtkFloatArray>::New();
    functions[i]->SetName(functions_names[i].c_str());
    table1->AddColumn(functions[i]);
  }

  int numPoints = 40;
  table1->SetNumberOfRows(numPoints);
  double * expA = new double[numPoints];
  double * expMinusA = new double[numPoints];
  double * exp2A = new double[numPoints];
  double ** d_functions = new double * [number_of_functions];
  
 

  for (int i = -2, j = 0; i <= 2; ++i, ++j)
  {

    table1->SetValue(j, 0, i); // second argument is for first column  
    expA[i] = exp(i);

    expMinusA[i] = exp(-i);
    exp2A[i] = exp(2*i);
    cout << i << " " <<  exp(i) << " " << exp(2*i) << endl;   
  }
  
  d_functions[0] = expA;
  d_functions[1] = expMinusA;
  d_functions[2] = exp2A;

  for (int n = 0; n < number_of_functions;++n)
    for (int i = 0; i < numPoints; ++i)  
    {
      functions[n]->SetValue(i,d_functions[n][i]); // second argument second column
    }
  

  // Set up the view
  vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);

  // Add multiple line plots, setting the colors etc
  vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
  chart->SetShowLegend(true);
  view->GetScene()->AddItem(chart);
  

  vtkPlot *line = chart->AddPlot(vtkChart::LINE);
  line->SetInputData(table1, 0, 1);// first column for x and second column for y
  line->SetColor(0, 255, 0, 255);
  line->SetWidth(2.0);
  line = chart->AddPlot(vtkChart::LINE);
  line->SetInputData(table1, 0, 2); // first cokli,net for x and second column for y
  line->SetColor(255, 0, 0, 255);
  line->SetWidth(2.0);
  #ifndef WIN32
    line->GetPen()->SetLineType(vtkPen::DASH_LINE);
  #endif
  
  line = chart->AddPlot(vtkChart::LINE);
  line->SetInputData(table1, 0, 3); // first cokli,net for x and second column for y
  line->SetColor(0, 0, 255, 255);
  line->SetWidth(2.0);
  
  #ifndef WIN32
  line->GetPen()->SetLineType(vtkPen::DASH_DOT_LINE);
  #endif
  // For dotted line, the line type can be from 2 to 5 for different dash/dot
  // patterns (see enum in vtkPen containing DASH_LINE, value 2):

  // (ifdef-ed out on Windows because DASH_LINE does not work on Windows
  //  machines with built-in Intel HD graphics card...)

  //view->GetRenderWindow()->SetMultiSamples(0);

  // Start interactor
  view->GetRenderWindow()->Render();
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

  return EXIT_SUCCESS;
}