C = g++
CCFLAGS = -O2 -pg
MACFLAGS= -framework OPENGL -framework GLUT
LINFLAGS32= -lX11 -lglut -lGL -lGLU -lz
LINFLAGS64= -lglut -lGL -lGLU -lz
CCDEBUGFLAGS = -g -pg
DEFAULTCHOICE = -D VAR_NOSEG
CATMULL = -D VAR_CATMULL
OUTNAME = runshark
HDEP = *.h
FILES =*.cpp

#runshark: $(FILES) $(HDEP)
#	$(C) $(DEFAULTCHOICE) $(CCFLAGS) *.cpp $(LINFLAGS32) -o $(OUTNAME)

catmull: $(FILES) $(HDEP)
	$(C) $(DEFAULTCHOICE) $(CATMULL)  $(CCFLAGS) *.cpp $(LINFLAGS32) -o $(OUTNAME)

#runshark64: $(FILES) $(HDEP)
#	$(C) $(DEFAULTCHOICE) $(CCFLAGS) *.cpp $(LINFLAGS64) -o $(OUTNAME)

debug: $(FILES) $(HDEP)
	$(C) $(DEFAULTCHOICE) $(CCDEBUGFLAGS) *.cpp $(LINFLAGS) -o $(OUTNAME) 

debug64: $(FILES) $(HDEP)
	$(C) $(DEFAULTCHOICE) $(CCDEBUGFLAGS) *.cpp $(LINFLAGS64) -o $(OUTNAME) 

Main.o: Main.cpp Globals.h
	g++ $(CFLAGS) -c Main.cpp

ArcBall.o: ArcBall.cpp ArcBall.h
	g++ $(CFLAGS) -c ArcBall.cpp

Texture.o: Texture.cpp Texture.h
	g++ $(CFLAGS) -c Texture.cpp

Vector.o: Vector.cpp Vector.h
	g++ $(CFLAGS) -c Vector.cpp

GPSconverter.o: GPSconverter.cpp GPSconverter.h Vector.h
	g++ $(CFLAGS) -c GPSconverter.cpp

Frustum.o: Frustum.cpp Frustum.h 
	g++ $(CFLAGS) -c Frustum.cpp

EXEreader.o: EXEreader.cpp EXEreader.h Vector.h
	g++ $(CFLAGS) -c EXEreader.cpp

ZOEreader.o: ZOEreader.cpp ZOEreader.h Vector.h
	g++ $(CFLAGS) -c ZOEreader.cpp

MATreader.o: MATreader.cpp MATreader
	g++ $(CFLAGS) -c MATreader.cpp

Mesh.o: Mesh.cpp Mesh.h Vector.h
	g++ $(CFLAGS) -c Mesh.cpp

glQuaternion.o: glQuaternion.cpp glQuaternion.h Vector.h
	g++ $(CFLAGS) -c glQuaternion.cpp

MyMat.o: MyMat.cpp MyMat.h Vector.h
	g++ $(CFLAGS) -c MyMat.cpp

SharkVertex.o: SharkVertex.cpp SharkVertex.h Vector.h
	g++ $(CFLAGS) -c SharkVertex.cpp

SharkMesh.o: SharkMesh.cpp SharkMesh.h SharkVertex.h Quad.h MyMat.h
	g++ $(CFLAGS) -c SharkMesh.cpp

Quad.o: Quad.cpp Quad.h Vector.h SharkVertex.h MyMat.h
	g++ $(CFLAGS) -c Quad.cpp

SharkBone.o: SharkBone.cpp SharkBone.h Quad.h glQuaternion.h SharkVertex.h Mesh.h SharkMesh.h MyMat.h
	g++ $(CFLAGS) -c SharkBone.cpp

ArcFrame.o: ArcFrame.cpp ArcFrame.h glQuaternion.h SharkBone.h
	g++ $(CFLAGS) -c ArcFrame.cpp

ArmTimeline.o: ArmTimeline.cpp ArmTimeline.h ArmFrame.h glQuaternion.h
	g++ $(CFLAGS) -c ArmTimeline.cpp

Keyframe.o: Keyframe.cpp Keyframe.h Quad.h MyMat.h Mesh.h glQuaternion.h SharkMesh.h
	g++ $(CFLAGS) -c Keyframe.cpp

FrameSequence.o: FrameSequence.cpp FrameSequence.h Keyframe.h
	g++ $(CFLAGS) -c FrameSequence.cpp

KeyframeSystem.o: KeyframeSystem.cpp KeyframeSystem.h Vector.h Quad.h FrameSequence.h SharkMesh.h
	g++ $(CFLAGS) -c KeyframeSystem.cpp

SharkBone.o: SharkBone.cpp SharkBone.h Quad.h glQuaternion.h SharkVertex.h Mesh.h SharkMesh.h MyMat.h
	g++ $(CFLAGS) -c SharkBone.cpp

SharkSkeleton.o: SharkSkeleton.cpp SharkSkeleton.h SharkBone.h Keyframe.h MyMat.h Mesh.h glQuaternion.h
	g++ $(CFLAGS) -c SharkSkeleton.cpp

SharkLoco.o: SharkLoco.cpp SharkLoco.h SharkSkeleton.h Keyframe.h MyMat.h Mesh.h SharkFacts.h
	g++ $(CFLAGS) -c SharkLoco.cpp

Shark.o: Shark.cpp Shark.h Mesh.h glQuaternion.h FrameSequence.h KeyframeSystem.h SharkLoco.h
	g++ $(CFLAGS) -c Shark.cpp

BlendArmAnimation.o: BlendArmAnimation.cpp BlendArmAnimation.h ArmTimeline.h SharkSkeleton.h SharkMesh.h
	g++ $(CFLAGS) -c BlendArmAnimation.cpp

SharkParticle.o: SharkParticle.cpp SharkParticle.h  Vector.h Texture.h MyMat.h
	g++ $(CFLAGS) -c SharkParticle.cpp

BubbleStream.o: BubbleStream.cpp BubbleStream.h SharkParticle.h
	g++ $(CFLAGS) -c BubbleStream.cpp

ParamFunctions.o: ParamFunctions.cpp ParamFunctions.h SplineTable.h ParamStructures.h SplineTable.h
	g++ $(CFLAGS) -c ParamFunctions.cpp

SplinePath.o: SplinePath.cpp SplinePath.h MATreader.h EXEreader.h ZOEreader.h ParamFunctions.h ParamStructure.h SplineTable.h GPSconverter.h Vector.h Frustum.h
	g++ $(CFLAGS) -c SplinePath.cpp

SplineTraveler.o: SplineTraveler.cpp SplineTraveler.h SplinePath.h Vector.h Frustum.h glQuaternion.h
	g++ $(CFLAGS) -c SplineTraveler.cpp

SharkWorld.o: SharkWorld.cpp SharkWorld.h Matreader.h EXEreader.h Vector.h SplinePath.h SplineTraveler.h Frustum.h
	g++ $(CFLAGS) -c SharkWorld.cpp


