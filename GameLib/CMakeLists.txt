project(GameLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h pch.h GameView.cpp GameView.h ids.h Game.cpp Game.h  Item.cpp Item.h Platform.cpp Platform.h Level.cpp Level.h Declaration.h SpartyGnome.cpp SpartyGnome.h PlatformDeclaration.cpp PlatformDeclaration.h Background.cpp Background.h Scoreboard.cpp Scoreboard.h Wall.cpp Wall.h Villain.cpp Villain.h ItemVisitor.h BackgroundDeclaration.cpp BackgroundDeclaration.h Money.cpp Money.h WallDeclaration.cpp WallDeclaration.h MoneyDeclaration.cpp MoneyDeclaration.h VillainDeclaration.cpp VillainDeclaration.h Stanley.cpp Stanley.h StanleyDeclaration.cpp StanleyDeclaration.h Door.cpp Door.h DoorDeclaration.cpp DoorDeclaration.h CopyVisitor.h Loan.cpp Loan.h LoanDeclaration.cpp LoanDeclaration.h CollisionVisitor.h CollisionVisitor.cpp Vector.cpp Vector.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)