# IoT_BlueThings
**집에서 간단하게 쓸 수 있는 Smart Home Hub를 구축**
- 스마트 스위치, 콘센트는 Brand Price로 인해서 직접 구매하기엔 가격 부담이 있어서 Arduino Kit와 Raspberry PI를 기반으로 하여 직접 제작을 하는 것에 대한 의의를 두었습니다.
- 기존에 나온 Smart Home Hub 키트들에 대하여 실생활과 연동을 할 수 있는 Smart Kit를 제공을 하는데 목표를 두었습니다.
- 실시간 생활 정보, 기기 작동 제어를 할 수 있는 Smart Desk에 대해서도 추가적으로 구현을 하였습니다.

**구상 목적**
- 기존의 제품들의 원거리 통신에 대한 불필요를 줄여 단거리 통신인 Bluetooth를 기반으로 제작하였습니다..
- 스마트 콘센트, 스마트 스위치를 Arduino 키트를 이용해서 간단한 구조를 이용하여 제작하였습니다.
- 기존 제품과는 달리 어린이나 노약자들도 쉽게 쓸 수 있도록 Kit를 만드는데 목표를 두었습니다.
- 모바일로는 블루투스 제어가 1대1 관계이지만 라즈베리파이를 이용해 1대 다 관계를 형성하였습니다.

## Team BlueThings
- 201332028 장승훈([wkdtndgns](https://github.com/wkdtndgns)) - Design, Arduino Kit, Web UI 구상
- 201332001 강인성([tails5555](https://github.com/tails5555)) - Mobile Application, Connector UI, Software Idea 제공

## Create Schedule
![bluethings_schedule](/image/bluethings_schedule.png "bluethings_schedule")

## Main Project Structure
![bluethings_structure02](/image/bluethings_structure02.png "bluethings_structure02")

## Final Structure Complete
![bluethings_structure01](/image/bluethings_structure01.png "bluethings_structure01")

## Using Languages
1. Smart Switch - `Arduino` `C++`
2. Smart Plug - `Arduino` `C++`
3. Mobile Application - `Android` `Java`
4. Web UI - `Spring Web MVC` `공공데이터 API` `Java` `JSP`
5. Connector UI - `Python`

## Smart Switch
> **스마트 스위치 구상도**
>
> ![bluethings_switch1](/image/bluethings_switch1.png "bluethings_switch1")

> **실제 제작 결과**
>
> ![bluethings_switch2](/image/bluethings_switch2.png "bluethings_switch2")

**적용 설명**
1. Bluetooth를 기반으로 제작하였습니다.
2. Bluetooth 통신을 통하여 서보 모터가 작동합니다.
3. 뒤에 부착된 보조배터리를 활용해 전력 공급을 하도록 설계하였습니다.

## Smart Plug
> **스마트 스위치 구상도**
> ![bluethings_plug2](/image/bluethings_plug2.png "bluethings_plug2")

> **실제 제작 결과**
>
> ![bluethings_plug1](/image/bluethings_plug1.png "bluethings_plug1")

**적용 설명**
1. Bluetooth를 기반으로 제작하였습니다.
2. 보조 배터리를 이용하여 작동 관리를 할 수 있습니다.
3. 터치 센서를 추가해서 원 터치를 통하여 전류 관리를 쉽게 할 수 있도록 설계하였습니다.
4. Solid State Relay를 이용해서 기존의 전자식 릴레이를 이용한 스마트 콘센서의 소음의 단점을 해결함과 동시에 누전 방지를 최소화를 하여 안전성을 보완하였습니다.

## Web UI
> **Web UI 적용 결과**
>
> ![bluethings_webUI](/image/bluethings_webUI.png "bluethings_webUI")

`pom.xml` 를 기반으로 Maven Dependency를 구성하여 Update Maven은 필수입니다. 이는 Raspberry PI에서 작동할 수 있도록 저용량으로 구상을 하였습니다. 공공데이터에 대해 실시간으로 받아오기 위해서는 **Wi-Fi** 환경으로 설정이 되어 있어야 합니다.

Maven `pom.xml`
```
<dependencies>
    <!-- 1. Spring Web MVC Starter -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>
    <!-- 2. Lombok Project -->
    <dependency>
        <groupId>org.projectlombok</groupId>
        <artifactId>lombok</artifactId>
        <optional>true</optional>
    </dependency>
    <!-- 3. Tomcat Starter -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-tomcat</artifactId>
        <scope>provided</scope>
    </dependency>
    <!-- 4. Spring Boot Test -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-test</artifactId>
        <scope>test</scope>
    </dependency>
    <!-- 5. JSON Encoding Library -->
    <dependency>
        <groupId>org.json</groupId>
        <artifactId>json</artifactId>
        <version>20171018</version>
    </dependency>
    <!-- 6. JSP JSTL -->
    <dependency>
        <groupId>javax.servlet</groupId>
        <artifactId>jstl</artifactId>
    </dependency>
</dependencies>
```

## Mobile Application
> **Mobile Application 구상도**
>
> ![bluethings_mobile2](/image/bluethings_mobile2.png "bluethings_mobile2")

> **Mobile Application 적용 결과**
> 
> ![bluethings_mobile1](/image/bluethings_mobile1.png "bluethings_mobile1")

**적용 설명**
- Mobile Device를 통하여 단거리 제어 기능을 탑재하였습니다.
- Switch 버튼을 이용 : 쉬운 조작을 통하여 기계와 친숙하지 않은 사람들도 손쉽게 제어가 가능합니다.
- Smart Switch, Smart Plug 등 새로운 Smart Device가 나오게 되어도 어플리케이션을 재활용 할 수 있는 호환성을 제공하였습니다.

## Conenctor UI
> **Connector UI 구상도 및 적용**
>
> ![bluethings_connectorUI](/image/bluethings_connectorUI.png "bluethings_connectorUI")

**적용 설명**
- Python 2.7 Tkinter 패키지와 Serial 패키지를 활용하여 Bluetooth를 기반으로 한 통신으로 데이터를 전송하는 원리로 작동을 제어하도록 설계하였습니다.
- Raspberry Pi Monitor에서 탑재한 터치 스크린 기능
을 활용해서 남녀노소가 쉽게 Smart Kit 들을 제어할 수
있도록 제작하였습니다.

## Reference Documents
- [사물인터넷 캡스톤 디자인 과제 결과 보고서](https://github.com/tails5555/IoT_Bluethings/blob/master/docs/BlueThings%20%EC%BA%A1%EC%8A%A4%ED%86%A4%EB%94%94%EC%9E%90%EC%9D%B8%EA%B3%BC%EC%A0%9C%EA%B2%B0%EA%B3%BC%EB%B3%B4%EA%B3%A0%EC%84%9C.pdf)
- [BlueThings 사용 설명서](https://github.com/tails5555/IoT_Bluethings/blob/master/docs/Bluethings_Operation_Menual.pdf)
- [사물인터넷 캡스톤 디자인 최종 발표](https://github.com/tails5555/IoT_Bluethings/blob/master/docs/Bluethings_%EC%82%AC%EB%AC%BC%EC%9D%B8%ED%84%B0%EB%84%B7_%EC%B5%9C%EC%A2%85_PPT.pdf)
- [사물인터넷 최종 결과 보고서 및 제안서](https://github.com/tails5555/IoT_Bluethings/blob/master/docs/Bluethings_%EC%8A%A4%EB%A7%88%ED%8A%B8%ED%99%88%ED%97%88%EB%B8%8C_%EC%B5%9C%EC%A2%85%EA%B2%B0%EA%B3%BC_%EB%B3%B4%EA%B3%A0%EC%84%9C.pdf)

## Awards
1. 사물인터넷 캡스톤 디자인 과목 **전원 A+**

## Thanks To
- 성공회대 소프트웨어공학과 **유상신 교수님**
- 성공회대 소프트웨어공학과 **이승진 교수님**
- 3D 프린팅 기술에 대하여 알려주신 **한상현 선배님**
- 실시간 버스 공공데이터 API를 제공하는 [서울특별시 교통정보과](http://api.bus.go.kr)