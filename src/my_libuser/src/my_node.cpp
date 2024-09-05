#include <rclcpp/rclcpp.hpp>

#include "my_libuser/my_libuser.hpp"

class MyNode : public rclcpp::Node {
public:
	MyNode() : Node("my_node") {
		LibraryUser lu;
		lu.use_library();
	}
};

int main(int argc, char* argv[]) {
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<MyNode>());
	rclcpp::shutdown();
	return 0;
}
