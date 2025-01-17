#include "spawnnuketitandatamodel.h"

SpawnNukeTitanDataModel::SpawnNukeTitanDataModel()
{

}

unsigned int
SpawnNukeTitanDataModel::
nPorts(QtNodes::PortType portType) const
{
  unsigned int result = 1;

  switch (portType)
  {
  case QtNodes::PortType::In:
      result = 1;
      break;

  case QtNodes::PortType::Out:
      result = 2;

    default:
      break;
  }

  return result;
}

QtNodes::NodeDataType
SpawnNukeTitanDataModel::
dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const
{
  switch(portType)
  {
  case QtNodes::PortType::In:
      return ExecutionData().type();
  case QtNodes::PortType::Out:
      if(portIndex == 0)
          return EntityData().type();
      else
          return ExecutionData().type();
  }
  return NodeDataType();
}
std::shared_ptr<QtNodes::NodeData>
SpawnNukeTitanDataModel::outData(QtNodes::PortIndex portIndex)
{
    if(portIndex == 0)
        return std::static_pointer_cast<QtNodes::NodeData>(_entities);
    else
        return std::static_pointer_cast<QtNodes::NodeData>(_execution);
}
