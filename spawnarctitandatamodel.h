#ifndef SPAWNARCTITANDATAMODEL_H
#define SPAWNARCTITANDATAMODEL_H

#include <QtWidgets/QLabel>
#include <vector>

#include "nodes/NodeDataModel.hpp"
#include "nodes/Connection.hpp"

#include "ExecutionData.h"
#include "EntityData.h"


class SpawnArcTitanDataModel : public QtNodes::NodeDataModel
{
    Q_OBJECT
public:
    SpawnArcTitanDataModel();

    QString caption() const override
    { return QStringLiteral("Spawn Arc Titan"); }

    bool captionVisible() const override
    { return true; }

    QString name() const override
    { return QStringLiteral("ArcTitan"); }

    QWidget *embeddedWidget() override { return nullptr; }

public:

    unsigned int
    nPorts(QtNodes::PortType portType) const override;

    QtNodes::NodeDataType
    dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

    std::shared_ptr<QtNodes::NodeData>
    outData(QtNodes::PortIndex port) override;

    ConnectionPolicy
    portInConnectionPolicy(QtNodes::PortIndex) const override
    {
      return ConnectionPolicy::Many;
    }

    void
    setInData(std::shared_ptr<QtNodes::NodeData> data, int) override {}

    void
    setInData(std::shared_ptr<QtNodes::NodeData> data, int, const QUuid& connectionId) override;

    ConnectionPolicy
    portOutConnectionPolicy(QtNodes::PortIndex portIndex) const override
    {
      if(portIndex == 0)
        return ConnectionPolicy::Many;
      else
        return ConnectionPolicy::One;
    }

private:
  QLabel *_label;
  std::shared_ptr<ExecutionData> _execution;
  std::shared_ptr<EntityData> _entities;
  std::vector<std::pair<QUuid, int>> inputExecution;
};

#endif // SPAWNARCTITANDATAMODEL_H
