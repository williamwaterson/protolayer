bin_PROGRAMS = proto.app

proto_app_SOURCES = \
src/protolayer/proto/exceptions/Exception.cpp \
src/protolayer/proto/view/visualisation/HeadsUpScene.cpp\
src/protolayer/proto/view/search/WebDelegate.m \
src/protolayer/proto/view/visualisation/HeadsUpControl.cpp \
src/protolayer/proto/view/visualisation/EditGeometryScene.cpp \
src/protolayer/proto/view/visualisation/ReferenceArrow.cpp \
src/protolayer/proto/view/visualisation/InstanceNode.cpp \
src/protolayer/proto/view/visualisation/DependencyArrow.cpp \
src/protolayer/proto/view/visualisation/LayerHexMesh.cpp \
src/protolayer/proto/view/visualisation/LayerPrism.cpp \
src/protolayer/proto/view/visualisation/LayeredScene.cpp \
src/protolayer/proto/view/visualisation/DomainScene.cpp \
src/protolayer/proto/view/visualisation/DomainNode.cpp \
src/protolayer/proto/view/visualisation/LayeredSceneSelectionModel.cpp \
src/protolayer/proto/view/visualisation/DomainSceneSelectionModel.cpp \
src/protolayer/proto/view/ViewLayer.cpp \
src/protolayer/proto/state/RenderingState.cpp \
src/protolayer/proto/state/InteractionState.cpp \
src/protolayer/proto/state/Perspective.cpp \
src/protolayer/proto/state/SearchPerspective.cpp \
src/protolayer/proto/state/ConceptPerspective.cpp \
src/protolayer/proto/state/InstancePerspective.cpp \
src/protolayer/proto/state/StateLayer.cpp \
src/protolayer/proto/state/SelectState.cpp \
src/protolayer/proto/state/SelectionModel.cpp \
src/protolayer/proto/state/Project.cpp \
src/protolayer/proto/controller/Interaction.cpp \
src/protolayer/proto/controller/GraphInteraction.cpp \
src/protolayer/proto/controller/interaction/Select.cpp \
src/protolayer/proto/controller/interaction/MoveCamera.cpp \
src/protolayer/proto/controller/interaction/PanCamera.cpp \
src/protolayer/proto/controller/interaction/TargetCamera.cpp \
src/protolayer/proto/controller/interaction/ZoomCamera.cpp \
src/protolayer/proto/controller/interaction/InstanceCreation.cpp \
src/protolayer/proto/controller/interaction/ReferenceCreation.cpp \
src/protolayer/proto/controller/action/CreateInstance.cpp \
src/protolayer/proto/controller/action/CreateReference.cpp \
src/protolayer/proto/controller/action/DeleteInstance.cpp \
src/protolayer/proto/controller/action/DeleteReference.cpp \
src/protolayer/proto/controller/action/SelectDomain.cpp \
src/protolayer/proto/controller/action/SelectInstance.cpp \
src/protolayer/proto/controller/action/SelectReference.cpp \
src/protolayer/proto/controller/action/SelectDependency.cpp \
src/protolayer/proto/controller/action/DeselectDomain.cpp \
src/protolayer/proto/controller/action/DeselectInstance.cpp \
src/protolayer/proto/controller/action/DeselectReference.cpp \
src/protolayer/proto/controller/action/DeselectDependency.cpp \
src/protolayer/proto/controller/action/PositionCamera.cpp \
src/protolayer/proto/controller/action/ZoomGranularity.cpp \
src/protolayer/proto/controller/action/ChangeLayer.cpp \
src/protolayer/proto/controller/ControllerLayer.cpp \
src/protolayer/proto/main.cpp

LIBS = \
-framework "WebKit" \
-framework "AppKit" \
-framework "Carbon" \
-framework "Cocoa" \
-framework "CoreServices" \
-framework "ApplicationServices" \
-framework "QuickTime" \
-framework "OpenGL" \
-framework "AGL" \
-framework "System" \
-dynamic /usr/lib/libobjc.A.dylib \
-dynamic /usr/lib/libm.dylib \
-dynamic /usr/lib/libxerces-c.dylib \
../common/lib_protolayer_common.la \
../containerservice/lib_protolayer_containerservice.la \
../concurrency/lib_protolayer_concurrency.la \
../animation/lib_protolayer_animation.la \
../nameservice/lib_protolayer_nameservice.la \
../naming/lib_protolayer_naming.la \
../server/lib_protolayer_server.la \
../pforms/lib_protolayer_pforms.la \
../dimensional/lib_protolayer_dimensional.la \
../assembly/lib_protolayer_assembly.la \
../carbon/lib_protolayer_carbon.la \
../linearalgebra/lib_protolayer_linearalgebra.la \
../iostream/lib_protolayer_iostream.la \
../ontology/lib_protolayer_ontology.la \
../pooling/lib_protolayer_pooling.la \
../ontologydto/lib_protolayer_ontologydto.la \
../net/lib_protolayer_net.la \
../renderer/lib_protolayer_renderer.la \
../style/lib_protolayer_style.la \
../geometry/lib_protolayer_geometry.la \
../subdivision/lib_protolayer_subdivision.la \
../xml/lib_protolayer_xml.la \
../server/lib_protolayer_server.la \
../logger/lib_protolayer_logger.la \
../fx/lib_protolayer_fx.la \
../util/lib_protolayer_util.la \
../scenegraph/lib_protolayer_scenegraph.la \
../workflow/lib_protolayer_workflow.la

DEFS = \
-I../assembly/src \
-I../concurrency/src \
-I../animation/src \
-I../naming/src \
-I../carbon/src \
-I../common/src \
-I../pforms/src \
-I../pooling/src \
-I../containerservice/src \
-I../nameservice/src \
-I../server/src \
-I../logger/src \
-I../dimensional/src \
-I../fx/src \
-I../geometry/src \
-I../scenegraph/src \
-I../subdivision/src \
-I../linearalgebra/src \
-I../iostream/src \
-I../net/src \
-I../ontology/src \
-I../ontologydto/src \
-I../renderer/src \
-I../style/src \
-I../xml/src \
-I../workflow/src \
-I../util/src

bundle:
	rm -rf proto.bundle
	mkdir proto.bundle
	mkdir proto.bundle/Contents
	mkdir proto.bundle/Contents/Resources
	mkdir proto.bundle/Contents/MacOS
	cp proto.app proto.bundle/Contents/MacOS
	cp etc/info.plist proto.bundle/Contents/
	cp -r etc/proto.nib proto.bundle/Contents/Resources
