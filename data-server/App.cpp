#include "controller/MyController.hpp"
#include "AppComponent.hpp"
#include "oatpp-libressl/Callbacks.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/core/base/CommandLineArguments.hpp"
#include <iostream>
#include <csignal>

/**
 *  This is the main file for the data server. 
 *  You shouldn't need to modify this file.
 *  run() method.
 *  1) set Environment components.
 *  2) add ApiController's endpoints to router
 *  3) run server
 */
void run() {
  
  /* set lockingCallback for libressl */
  oatpp::libressl::Callbacks::setDefaultCallbacks();
  
  /* ignore SIGPIPE */
  #if !(defined(WIN32) || defined(_WIN32))
    std::signal(SIGPIPE, SIG_IGN);
  #endif
  
  //cout << "creating components" << endl;
  AppComponent components; // Create scope Environment components
  //cout << "components created" << endl;
 /* create ApiControllers and add endpoints to router */
  cout << "getting router" << endl;
  auto router = components.httpRouter.getObject();
  //cout << "router created" << endl;
  cout << "creating controller" << endl; 
  //auto myController = MyController::createShared();
  router->addController(MyController::createShared());
  cout << "controller created" << endl; 
  //myController->addEndpointsToRouter(router); // Add api endpoints
  cout << "endpoints added" << endl; 
  
  /* create server */
  oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                components.serverConnectionHandler.getObject());
  
  OATPP_LOGD("Server", "Running on port %s...", components.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str()); 
  server.run();
}

/**
 *  main
 */
int main(int argc, const char * argv[]) {

  oatpp::base::Environment::init();

   run();
  //run(oatpp::base::CommandLineArguments(argc, argv));
  
  /* Print how much objects were created during app running, and what have left-probably leaked */
  /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";
  
  oatpp::base::Environment::destroy();
  
  return 0;
}
