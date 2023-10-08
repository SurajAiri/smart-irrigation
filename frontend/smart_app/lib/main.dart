import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:smart_app/routes/routes.dart';

void main() {
  runApp(const SmartApp());
}

class SmartApp extends StatelessWidget {
  const SmartApp({super.key});

  @override
  Widget build(BuildContext context) {
    return GetMaterialApp(
      getPages: MyRoutes.routes,
    );
  }
}
