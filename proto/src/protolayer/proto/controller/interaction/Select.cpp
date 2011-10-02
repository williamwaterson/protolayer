#include "Select.h"
#include <iostream.h>

namespace protolayer
{ 

namespace proto
{

namespace interaction
{

Select::Select(StateLayer& stateLayer) :
  protolayer::proto::GraphInteraction(stateLayer)
{
  _domainAppearance = new style::Appearance();
  _selectedDomainAppearance = new style::Appearance();

  _domainAppearance->getColor()[0] = 1.0f;
  _domainAppearance->getColor()[1] = 1.0f;
  _domainAppearance->getColor()[2] = 1.0f;
  _domainAppearance->getColor()[3] = 1.0f;

  _selectedDomainAppearance->getColor()[0] = 1.0f;
  _selectedDomainAppearance->getColor()[1] = 0.8f;
  _selectedDomainAppearance->getColor()[2] = 0.0f;
  _selectedDomainAppearance->getColor()[3] = 1.0f;  
}


Select::~Select()
{
}


void Select::mouseDown(float x, float y, int clickCount)
{
  protolayer::proto::GraphInteraction::mouseDown(x, y, clickCount);

  SelectionModel& selectionModel = getStateLayer().getSelectionModel();
  scenegraph::HitModel& hitModel = getStateLayer().getViewLayer().getCurrentShot().getHitModel();

  scenegraph::Node* hitNode = hitModel.getHit();
  if (clickCount == 2) {
    if (hitModel.getHit() != 0) {
      scenegraph::Node* node = hitModel.getHit();
      DomainNode* domainNode = dynamic_cast <DomainNode*> (node);
      if (domainNode != 0) {
	scenegraph::Shot& shot = domainNode->getShot();
	getStateLayer().getViewLayer().setCurrentShot(shot);
      }
    }

  } else if (clickCount == 1) {

    if (hitNode != 0) {

      DomainNode* domainNode = dynamic_cast <DomainNode*> (hitNode);
      if (domainNode != 0) {
	if (selectionModel.contains(*hitNode)) {
	  //	  selectionModel.remove(*hitNode);
	  //	  domainNode->getFaces().setAppearance(*_domainAppearance);	  
	} else {
	  SelectionModel::NodeIteratorType iter;
	  for (iter = selectionModel.getNodes(); iter != selectionModel.getLastNode(); iter++) {
	    scenegraph::Node* node = *iter;
	    DomainNode* domainNode = dynamic_cast <DomainNode*> (node);
	    if (domainNode != 0) {
	      domainNode->getFaces().setAppearance(*_domainAppearance);
	    }
	  }

	  selectionModel.clear();

	  selectionModel.add(*hitNode);
	  domainNode->getFaces().setAppearance(*_selectedDomainAppearance);
	}
      } else {
	SelectionModel::NodeIteratorType iter;
	for (iter = selectionModel.getNodes(); iter != selectionModel.getLastNode(); iter++) {
	  scenegraph::Node* node = *iter;
	  DomainNode* domainNode = dynamic_cast <DomainNode*> (node);
	  if (domainNode != 0) {
	    domainNode->getFaces().setAppearance(*_domainAppearance);
	  }
	}

	selectionModel.clear();
      }
    } else {
      SelectionModel::NodeIteratorType iter;
      for (iter = selectionModel.getNodes(); iter != selectionModel.getLastNode(); iter++) {
	scenegraph::Node* node = *iter;
	DomainNode* domainNode = dynamic_cast <DomainNode*> (node);
	if (domainNode != 0) {
	  domainNode->getFaces().setAppearance(*_domainAppearance);
	}
      }

      selectionModel.clear();
    }
  }

  getStateLayer().getViewLayer().swapRendererPortsAndDisplay();
}


void Select::mouseMoved(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseMoved(x, y);
}


void Select::mouseDragged(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseDragged(x, y);




  /*
  GraphInteractionState::mouseDown(callRef, event);

  scenegraph::Shot& shot = _viewPane->getDomainShot();
  _scene = &(getRenderPane().getSpace().getShots().next().getScene());
  _hitModel = &(shot.getHitModel());

  UInt32 clickCount;
  GetEventParameter(event, kEventParamClickCount, typeUInt32, NULL, sizeof(clickCount), NULL, &clickCount);

  if (clickCount == 1) {

    if (_hitModel->getHit() != 0) {
      clearSelection();
      scenegraph::Node* item = _hitModel->getHit();
      if (typeid(*item) == typeid(DomainPrism)) {
        DomainPrism& domainPrism = dynamic_cast <DomainPrism&> (*item);
        addToSelection(domainPrism);
      }
    }

  } else if (clickCount == 2) {

    if (_hitModel->getHit() != 0) {
      scenegraph::Node* item = _hitModel->getHit();
      if (typeid(*item) == typeid(DomainPrism)) {
        DomainPrism* domain = dynamic_cast <DomainPrism*> (item);
        domain->getFaces().setAppearance(_selectedDomainAppearance);
        triggerChangeToLayeredSceneMode(*domain);
      }
    }
  }

  //  getRenderPane().getSpace().evalPlanarMousePosition();  
  getRenderPane().getSpace().display();

  return eventNotHandledErr;
  */
}


void Select::mouseUp(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseUp(x, y);
}


void Select::keyDown()
{
}


void Select::keyUp()
{
}


}


}


}
