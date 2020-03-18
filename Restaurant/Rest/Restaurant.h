#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "..\PiriortyQueue.h"

#include "Order.h"
#include "Cook.h"
#include <istream>
#include <ostream>
using namespace std;
// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file

	Queue<Cook*> Unavailable_Cooks;
	Queue<Cook*> VIP_Cooks;
	Queue<Cook*> Vegan_Cooks;
	Queue<Cook*> Normal_Cooks;
	PiriorityQueue<Order*> VIP_Orders;
	PiriorityQueue<Order*> Vegan_Orders;
	PiriorityQueue<Order*> Normal_Orders;

	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo

	/// ==>
	
	
	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Restaurant();
	~Restaurant();
	
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	void ReadInputs();


	void FillDrawingList();

	//
	// TODO: Add More Member Functions As Needed
	//


/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 

	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue
	void AddtoVIPQueue(Order* po,int Pir);
	void AddtoNormalQueue(Order* po, int Pir);
	void AddtoVeganQueue(Order* po, int Pir);


/// ================================================================================================== 



};

#endif