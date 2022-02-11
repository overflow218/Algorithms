import 'comment.dart';

class Post {
  Post({
    required this.posterUid,
    required this.posterName,
    required this.posterImg,
    required this.date,
    required this.bodytext,
    required this.image,
    required this.comments,
    required this.like,
    required this.amazed,
    required this.laugh,
    required this.sad,
    required this.angry,
    required this.reaction,
  });

  late String posterUid;
  late String posterName;
  late String posterImg;
  late DateTime date;
  late String bodytext;
  late String image;
  // late List<Comment> comments;
  // late List<String> like; //좋아요
  // late List<String> amazed; //놀람
  // late List<String> laugh; //웃김
  // late List<String> sad; //슬픔
  // late List<String> angry; //화남
  late List<dynamic> comments;
  late List<dynamic> like; //좋아요
  late List<dynamic> amazed; //놀람
  late List<dynamic> laugh; //웃김
  late List<dynamic> sad; //슬픔
  late List<dynamic> angry; //화남
  late int reaction; //내 반응. 0->반응하지 않음, 1 ->좋아요, 2-> 놀람, 3->웃김, 4->슬픔, 5->화

  Post.fromjson(Map<String, dynamic> data) {
    posterUid = data['posterUid'];
    posterName = data['posterName'];
    posterImg = data['posterImg'];
    date = DateTime.fromMicrosecondsSinceEpoch(
        data['date'].microsecondsSinceEpoch);
    bodytext = data['bodytext'];
    comments = data['comments'];
    image = data['image'];
    like = data['like'];
    amazed = data['amazed'];
    laugh = data['laugh'];
    sad = data['sad'];
    angry = data['angry'];
    reaction = data['reaction'];
  }

  Map<String, dynamic> toJson() {
    Map<String, dynamic> data = {};
    data['posterUid'] = this.posterUid;
    data['posterName'] = this.posterName;
    data['posterImg'] = this.posterImg;
    data['date'] = this.date;
    data['bodytext'] = this.bodytext;
    data['comments'] = this.comments;
    data['image'] = this.image;
    data['like'] = this.like;
    data['amazed'] = this.amazed;
    data['laugh'] = this.laugh;
    data['sad'] = this.sad;
    data['angry'] = this.angry;
    data['reaction'] = this.reaction;
    return data;
  }
}

import 'package:crayon/views/02_sns/sns_comment_view.dart';
import 'package:expandable/expandable.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:hexcolor/hexcolor.dart';
import 'package:http/http.dart';
import 'package:intl/intl.dart';
import 'package:flutter/services.dart';
import 'package:crayon/models/comment.dart';
import 'package:crayon/models/post.dart';
import 'package:custom_pop_up_menu/custom_pop_up_menu.dart';

import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter_image_compress/flutter_image_compress.dart';
import 'dart:async';
import 'dart:io';
import 'package:firebase_core/firebase_core.dart';
import 'package:image_picker/image_picker.dart';
import 'package:firebase_storage/firebase_storage.dart' as firebase_storage;
import 'package:flutter_native_image/flutter_native_image.dart';
import 'package:crayon/global.dart' as global;

class SNSView extends StatefulWidget {
  const SNSView({Key? key}) : super(key: key);

  @override
  _SNSViewState createState() => _SNSViewState();
}

class ItemModel {
  String title;
  String icon;
  int index;

  ItemModel(this.title, this.icon, this.index);
}

const loremIpsum =
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

class _SNSViewState extends State<SNSView> {
  final ScrollController _scrollController = ScrollController();
  // CustomPopupMenuController _popupMenuController = CustomPopupMenuController();

  List<ItemModel> menuItems = [
    ItemModel('좋아요', '\u{1F44D}', 1),
    ItemModel('놀라워요', '\u{1F632}', 2),
    ItemModel('웃겨요', '\u{1F602}', 3),
    ItemModel('슬퍼요', '\u{1F622}', 4),
    ItemModel('화나요', '\u{1F621}', 5),
  ];

  String _uid = FirebaseAuth.instance.currentUser!.uid;

  // 추가 데이터 가져올때 하단 인디케이터 표시용
  bool isMoreRequesting = false;

  // 다음 데이터 위치를 파악하기 위함
  int nextPage = 0;

  // 서버에 저장되어 있는 데이터들(가상으로 사용하기 위해)
  List<Post> serverItems = [];

  // 실제 데이터를 서버에 가져와 저장되는 데이터(리스트에 표시할때 사용)
  List<Post> items = [];

  // 현재 유저이름
  String userName = global.name;

  // 현재 유저 이미지
  String userImg = global.userImg;

  CollectionReference posts = FirebaseFirestore.instance.collection('posts');

  Future<void> _showMyDialog() async {
    File? _image;
    final picker = ImagePicker();

    TextEditingController _controller = TextEditingController();
    // 갤러리에서 사진 가져오기
    Future _getImage() async {
      final pickedFile = await picker.pickImage(
          source: ImageSource.gallery,
          maxWidth: null,
          maxHeight: null,
          imageQuality: null);
      setState(() {
        // _image = File(pickedFile!.path);
        if (pickedFile != null) {
          _image = File(pickedFile.path);
        }
      });
    }

    Future<File> compressFile(File file) async {
      final filePath = file.absolute.path;
      // Create output file path
      // eg:- "Volume/VM/abcd_out.jpeg"
      final lastIndex = filePath.lastIndexOf(new RegExp(r'.jp'));
      final splitted = filePath.substring(0, (lastIndex));
      final outPath = "${splitted}_out${filePath.substring(lastIndex)}";
      var result = await FlutterImageCompress.compressAndGetFile(
        file.absolute.path,
        outPath,
        quality: 5,
      );
      print(file.lengthSync());
      print(result!.lengthSync());
      return result;
    }

    Future _uploadFile(BuildContext context) async {
      try {
        // 파일 압축해주기
        _image = await compressFile(_image!);
        // 스토리지에 업로드할 파일 경로
        final firebaseStorageRef = firebase_storage.FirebaseStorage.instance
            .ref()
            .child('SNSImages')
            .child('${DateTime.now().millisecondsSinceEpoch}.png');
        print('파일 업로드 합니다');
        // 파일 업로드
        final uploadTask = firebaseStorageRef.putFile(_image!,
            firebase_storage.SettableMetadata(contentType: 'image/png'));
        // 완료까지 기다림
        await uploadTask.whenComplete(() => null);
        // 업로드 완료 후 url
        final downloadUrl = await firebaseStorageRef.getDownloadURL();
        print('파이어 베이스에도 업로드 합니다');

        // post 클래스를 만들고 그걸 넣어줄거임.
        Post newPost = Post(
            posterUid: _uid,
            posterName: userName,
            posterImg: userImg,
            date: DateTime.now(),
            bodytext: _controller.text,
            image: downloadUrl,
            comments: [],
            like: [],
            amazed: [],
            laugh: [],
            sad: [],
            angry: [],
            reaction: 0);

        // // 문서 작성
        // await FirebaseFirestore.instance.collection('posts').add({
        //   'bodytext': _controller.text,
        //   'date': DateTime.now(),
        //   'image': downloadUrl,
        //   'posterUid': _uid,
        // });

        // 문서 작성
        await FirebaseFirestore.instance
            .collection('posts')
            .add(newPost.toJson());
      } catch (e) {
        print(e);
      }
      // 완료 후 앞 화면으로 이동
      Navigator.pop(context);
    }

    return showDialog<void>(
      context: context,
      barrierDismissible: false, // user must tap button!
      builder: (BuildContext context) {
        return StatefulBuilder(builder: (context, StateSetter setState) {
          return AlertDialog(
            contentPadding: EdgeInsets.fromLTRB(0, 0, 0, 0),
            content: SingleChildScrollView(
                child: Container(
              width: 800,
              height: 600,
              child: Column(
                children: [
                  Padding(
                    padding: EdgeInsets.fromLTRB(0, 10, 0, 0),
                    child: Row(
                      children: [
                        IconButton(
                          onPressed: () => Navigator.pop(context),
                          icon: Icon(
                            Icons.arrow_back,
                            color: Colors.black,
                          ),
                        ),
                        Expanded(
                          child: Text(
                            '  새 게시물',
                            style: TextStyle(color: Colors.black, fontSize: 25),
                          ),
                        ),
                        IconButton(
                            onPressed: () async {
                              final pickedFile = await picker.pickImage(
                                  source: ImageSource.gallery,
                                  maxWidth: null,
                                  maxHeight: null,
                                  imageQuality: null);
                              // _image = File(pickedFile!.path);
                              if (pickedFile != null) {
                                setState(() {
                                  _image = File(pickedFile.path);
                                });
                              }
                            },
                            icon: Icon(Icons.camera_alt)),
                        IconButton(
                          onPressed: () async {
                            _uploadFile(context);
                          },
                          tooltip: '업로드',
                          icon: Icon(
                            Icons.check,
                            color: Colors.blue,
                          ),
                        ),
                      ],
                    ),
                  ),
                  _image != null
                      ? SizedBox(
                          child: Image.file(
                            File(_image!.path),
                            // fit: BoxFit.cover,
                          ),
                          height: MediaQuery.of(context).size.height / 2,
                          width: MediaQuery.of(context).size.width,
                          // height: 100,
                          // width: 100,
                        )
                      : Container(),
                  Expanded(
                    child: Container(
                      child: Padding(
                        padding: EdgeInsets.fromLTRB(30, 40, 30, 0),
                        child: TextField(
                          style: TextStyle(fontSize: 20),
                          controller: _controller,
                          decoration:
                              InputDecoration.collapsed(hintText: '문구 입력'),
                        ),
                      ),
                    ),
                  )
                ],
              ),
            )),
          );
        });
      },
    );
  }

  Future<void> getSNS() async {
    QuerySnapshot querySnapshot = await posts.get();
    serverItems = querySnapshot.docs
        .map((doc) => Post.fromjson(doc.data() as Map<String, dynamic>))
        .toList();
    items = serverItems;
    print('서버에서 sns가져왔어요');
    print(items);
    print(items[0].bodytext);
    print(items[0].date);
    print(items[0].posterName);
    print(items[0].image);
  }

  @override
  initState() {
    // // 서버의 가상데이터 150개 만들어둠
    // for (var i = 0; i < 150; i++) {
    //   Post post = new Post(
    //     posterUid: 'JWbqazOzhYhmKraoKVh9P1jlQq83',
    //     posterName: '김민수',
    //     posterImg: '',
    //     date: DateTime.now(),
    //     bodytext: loremIpsum,
    //     image:
    //         'https://images.unsplash.com/photo-1484406566174-9da000fda645?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=989&q=80',
    //     comments: [
    //       Comment(
    //           commenterUid: 'JWbqazOzhYhmKraoKVh9P1jlQq83',
    //           commenterName: '박준영',
    //           date: DateTime.now(),
    //           bodytext: '오 멋져요!!')
    //     ],
    //     like: [
    //       'ZUUqIiwEWScFV23uQYml7VmWZ3e2',
    //       'ZUUqIiwEWScFV23uQYml7VmWZ3sdf2'
    //     ],
    //     amazed: ['ZUUqIiwEWScFV23uQYml7VmWZ'],
    //     laugh: [],
    //     sad: [],
    //     angry: [],
    //     reaction: 1,
    //   );
    //   // post.posterName = '김민수';
    //   serverItems.add(post);
    // }
    // requestNew();

    // 스크롤 컨트롤러 다는건데 잠시 주석처리함
    // _scrollController.addListener(() {
    //   if (_scrollController.position.pixels ==
    //           _scrollController.position.maxScrollExtent &&
    //       !_scrollController.position.outOfRange) {
    //     requestMore();
    //     print('스크롤이 맨 바닥에 위치해 있습니다');
    //   } else if (_scrollController.offset ==
    //           _scrollController.position.minScrollExtent &&
    //       !_scrollController.position.outOfRange) {
    //     requestNew();
    //     print('스크롤이 맨 위에 위치해 있습니다');
    //   }
    // });
    super.initState();
  }

  @override
  void didChangeDependencies() async {
    // TODO: implement didChangeDependencies
    super.didChangeDependencies();
    // requestNew();
  }

  @override
  void dispose() {
    _scrollController.dispose();
    super.dispose();
  }

  // 서버에서 처음 데이터 가져오기
  Future<void> requestNew() async {
    print('request New');
    //
    nextPage = 0;
    items.clear();
    setState(() {
      items += serverItems.sublist(nextPage * 10, (nextPage * 10) + 15);
      // 다음을 위해 페이지 증가
      nextPage += 1;
    });

    // 데이터 가져오는 동안 효과를 보여주기 위해 약 1초간 대기하는 것
    // 실제 서버에서 가져올땐 필요없음
    return await Future.delayed(Duration(milliseconds: 1000));
  }

  // 서버에서 추가 데이터 가져올 때
  Future<void> requestMore() async {
    // 해당부분은 서버에서 가져오는 내용을 가상으로 만든 것이기 때문에 큰 의미는 없다.

    // 읽을 데이터 위치 얻기
    int nextDataPosition = (nextPage * 10);
    // 읽을 데이터 크기
    int dataLength = 10;

    // 읽을 데이터가 서버에 있는 데이터 총 크기보다 크다면 더이상 읽을 데이터가 없다고 판다.
    if (nextDataPosition > serverItems.length) {
      // 더이상 가져갈 것이 없음
      return;
    }

    // 읽을 데이터는 있지만 10개가 안되는 경우
    if ((nextDataPosition + 10) > serverItems.length) {
      // 가능한 최대 개수 얻기
      dataLength = serverItems.length - nextDataPosition;
    }
    setState(() {
      // 데이터 읽기
      items +=
          serverItems.sublist(nextDataPosition, nextDataPosition + dataLength);

      // 다음을 위해 페이지 증가
      nextPage += 1;
    });

    // 가상으로 잠시 지연 줌
    return await Future.delayed(Duration(milliseconds: 1000));
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
        future: getSNS(),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.done) {
            return Scaffold(
              backgroundColor: HexColor('F7F7F7'),
              body: ListView.builder(
                controller: _scrollController,
                itemCount: items.length,
                itemBuilder: (context, index) {
                  return ExpandableNotifier(
                    child: Card(
                      clipBehavior: Clip.antiAlias,
                      child: Padding(
                        padding: EdgeInsets.all(8),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            //작성자 프로필
                            Row(
                              // crossAxisAlignment: CrossAxisAlignment.start,
                              // mainAxisAlignment: MainAxisAlignment.center,
                              children: [
                                CircleAvatar(
                                  backgroundImage:
                                      // NetworkImage(items[index].image),
                                      NetworkImage(items[index].posterImg),
                                ),
                                SizedBox(
                                  width: 5,
                                ),
                                Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: [
                                    Text(items[index].posterName),
                                    Text(DateFormat('MM월 dd일')
                                        .format(items[index].date)),
                                  ],
                                ),
                              ],
                            ),
                            SizedBox(
                              height: 10,
                            ),
                            //사진
                            Container(
                              height: 300,
                              decoration: BoxDecoration(
                                image: DecorationImage(
                                  image: NetworkImage(items[index].image),
                                  fit: BoxFit.cover,
                                ),
                              ),
                            ),
                            SizedBox(
                              height: 10,
                            ),
                            //글
                            ScrollOnExpand(
                              scrollOnExpand: true,
                              scrollOnCollapse: false,
                              child: ExpandablePanel(
                                theme: const ExpandableThemeData(
                                  headerAlignment:
                                      ExpandablePanelHeaderAlignment.center,
                                  tapBodyToCollapse: true,
                                ),
                                header: Padding(
                                    padding: EdgeInsets.all(10),
                                    child: Text(
                                      items[index].posterName,
                                      // style: Theme.of(context).textTheme.body2,
                                    )),
                                collapsed: Text(
                                  items[index].bodytext,
                                  softWrap: true,
                                  maxLines: 2,
                                  overflow: TextOverflow.ellipsis,
                                ),
                                expanded: Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: <Widget>[
                                    for (var _ in Iterable.generate(5))
                                      Padding(
                                          padding: EdgeInsets.only(bottom: 10),
                                          child: Text(
                                            items[index].bodytext,
                                            softWrap: true,
                                            overflow: TextOverflow.fade,
                                          )),
                                  ],
                                ),
                                builder: (_, collapsed, expanded) {
                                  return Padding(
                                    padding: EdgeInsets.only(
                                        left: 10, right: 10, bottom: 10),
                                    child: Expandable(
                                      collapsed: collapsed,
                                      expanded: expanded,
                                      theme: const ExpandableThemeData(
                                          crossFadePoint: 0),
                                    ),
                                  );
                                },
                              ),
                            ),
                            //감정 표현들, 나의 감정표현
                            StatefulBuilder(builder: (context, setState) {
                              CustomPopupMenuController _popupMenuController =
                                  CustomPopupMenuController();

                              return Row(
                                  mainAxisAlignment:
                                      MainAxisAlignment.spaceBetween,
                                  children: [
                                    //감정 표현들
                                    GestureDetector(
                                      onLongPress: () {
                                        HapticFeedback.lightImpact();
                                        print("누가 감정표현했는지 보여주기");
                                        showModalBottomSheet<void>(
                                          context: context,
                                          builder: (BuildContext context) {
                                            return Container(
                                              height: MediaQuery.of(context)
                                                      .size
                                                      .height *
                                                  2 /
                                                  5,
                                              color: Colors.white,
                                              child: Padding(
                                                padding: EdgeInsets.all(10.0),
                                                child: Column(
                                                  mainAxisAlignment:
                                                      MainAxisAlignment.start,
                                                  crossAxisAlignment:
                                                      CrossAxisAlignment.start,
                                                  // mainAxisSize: MainAxisSize.min,
                                                  children: <Widget>[
                                                    Row(
                                                      children: [
                                                        SizedBox(width: 2),
                                                        Text(
                                                            '총 ${items[index].like.length + items[index].amazed.length + items[index].laugh.length + items[index].sad.length + items[index].angry.length}'),
                                                        SizedBox(width: 5),
                                                        items[index]
                                                                    .like
                                                                    .length ==
                                                                0
                                                            ? Container()
                                                            : Text(
                                                                '\u{1F44D} ${items[index].like.length.toString()}  '),
                                                        items[index]
                                                                    .amazed
                                                                    .length ==
                                                                0
                                                            ? Container()
                                                            : Text(
                                                                '\u{1F632} ${items[index].amazed.length.toString()}  '),
                                                        items[index]
                                                                    .laugh
                                                                    .length ==
                                                                0
                                                            ? Container()
                                                            : Text(
                                                                '\u{1F602} ${items[index].laugh.length.toString()}  '),
                                                        items[index]
                                                                    .sad
                                                                    .length ==
                                                                0
                                                            ? Container()
                                                            : Text(
                                                                '\u{1F622} ${items[index].sad.length.toString()}  '),
                                                        items[index]
                                                                    .angry
                                                                    .length ==
                                                                0
                                                            ? Container()
                                                            : Text(
                                                                '\u{1F621} ${items[index].angry.length.toString()}'),
                                                      ],
                                                    ),
                                                    // ListView(
                                                    //
                                                    // ),
                                                    // const Text('Modal BottomSheet'),
                                                    // ElevatedButton(
                                                    //   child: const Text('Close BottomSheet'),
                                                    //   onPressed: () => Navigator.pop(context),
                                                    // )
                                                  ],
                                                ),
                                              ),
                                            );
                                          },
                                        );
                                      },
                                      child: Row(
                                        children: [
                                          SizedBox(width: 2),
                                          items[index].like.length == 0
                                              ? Container()
                                              : Text(
                                                  '\u{1F44D} ${items[index].like.length.toString()}  '),
                                          items[index].amazed.length == 0
                                              ? Container()
                                              : Text(
                                                  '\u{1F632} ${items[index].amazed.length.toString()}  '),
                                          items[index].laugh.length == 0
                                              ? Container()
                                              : Text(
                                                  '\u{1F602} ${items[index].laugh.length.toString()}  '),
                                          items[index].sad.length == 0
                                              ? Container()
                                              : Text(
                                                  '\u{1F622} ${items[index].sad.length.toString()}  '),
                                          items[index].angry.length == 0
                                              ? Container()
                                              : Text(
                                                  '\u{1F621} ${items[index].angry.length.toString()}'),
                                        ],
                                      ),
                                    ),
                                    //나의 감정표현
                                    CustomPopupMenu(
                                      child: Padding(
                                          padding:
                                              EdgeInsets.fromLTRB(3, 0, 3, 0),
                                          child: items[index].reaction == 0
                                              ? Icon(
                                                  Icons.add_reaction_outlined,
                                                  size: 20,
                                                )
                                              : items[index].reaction == 1
                                                  ? Text(
                                                      '\u{1F44D}',
                                                      style: TextStyle(
                                                          fontSize: 20),
                                                    )
                                                  : items[index].reaction == 2
                                                      ? Text(
                                                          '\u{1F632}',
                                                          style: TextStyle(
                                                              fontSize: 20),
                                                        )
                                                      : items[index].reaction ==
                                                              3
                                                          ? Text(
                                                              '\u{1F602}',
                                                              style: TextStyle(
                                                                  fontSize: 20),
                                                            )
                                                          : items[index]
                                                                      .reaction ==
                                                                  4
                                                              ? Text(
                                                                  '\u{1F622}',
                                                                  style: TextStyle(
                                                                      fontSize:
                                                                          20),
                                                                )
                                                              : Text(
                                                                  '\u{1F621}',
                                                                  style: TextStyle(
                                                                      fontSize:
                                                                          20),
                                                                )),
                                      menuBuilder: () => ClipRRect(
                                        borderRadius: BorderRadius.circular(5),
                                        child: Container(
                                          // color: const Color(0xFF4C4C4C),
                                          color: Colors.white,
                                          child: IntrinsicWidth(
                                            child: Column(
                                              crossAxisAlignment:
                                                  CrossAxisAlignment.stretch,
                                              children: menuItems
                                                  .map(
                                                    (item) => GestureDetector(
                                                      behavior: HitTestBehavior
                                                          .translucent,
                                                      onTap: () {
                                                        print(
                                                            "onTap ${item.title} ${item.index}");
                                                        _popupMenuController
                                                            .hideMenu();
                                                        setState(() {
                                                          //이전거 빼고
                                                          switch (items[index]
                                                              .reaction) {
                                                            case 1:
                                                              {
                                                                items[index]
                                                                    .like
                                                                    .remove(
                                                                        _uid);
                                                                break;
                                                              }
                                                            case 2:
                                                              {
                                                                items[index]
                                                                    .amazed
                                                                    .remove(
                                                                        _uid);
                                                                break;
                                                              }
                                                            case 3:
                                                              {
                                                                items[index]
                                                                    .laugh
                                                                    .remove(
                                                                        _uid);
                                                                break;
                                                              }
                                                            case 4:
                                                              {
                                                                items[index]
                                                                    .sad
                                                                    .remove(
                                                                        _uid);
                                                                break;
                                                              }
                                                            case 5:
                                                              {
                                                                items[index]
                                                                    .angry
                                                                    .remove(
                                                                        _uid);
                                                                break;
                                                              }
                                                          }

                                                          //새로운거 넣고
                                                          switch (item.index) {
                                                            case 1:
                                                              {
                                                                items[index]
                                                                    .like
                                                                    .add(_uid);
                                                                break;
                                                              }
                                                            case 2:
                                                              {
                                                                items[index]
                                                                    .amazed
                                                                    .add(_uid);
                                                                break;
                                                              }
                                                            case 3:
                                                              {
                                                                items[index]
                                                                    .laugh
                                                                    .add(_uid);
                                                                break;
                                                              }
                                                            case 4:
                                                              {
                                                                items[index]
                                                                    .sad
                                                                    .add(_uid);
                                                                break;
                                                              }
                                                            case 5:
                                                              {
                                                                items[index]
                                                                    .angry
                                                                    .add(_uid);
                                                                break;
                                                              }
                                                          }

                                                          //reaction 바꾸고
                                                          items[index]
                                                                  .reaction =
                                                              item.index;

                                                          //여기에서 firebase 업데이트. UI에는 보여주지 않음(firebase에서 가져오는 건 위에서 잡아당겼을 때만!)
                                                        });
                                                      },
                                                      child: Container(
                                                        height: 40,
                                                        padding: EdgeInsets
                                                            .symmetric(
                                                                horizontal: 20,
                                                                vertical: 5),
                                                        child: Column(
                                                          children: <Widget>[
                                                            Text(
                                                              item.icon,
                                                            ),
                                                            Text(
                                                              item.title,
                                                              style: TextStyle(
                                                                color: Colors
                                                                    .black,
                                                                fontSize: 12,
                                                              ),
                                                            ),
                                                          ],
                                                        ),
                                                      ),
                                                    ),
                                                  )
                                                  .toList(),
                                            ),
                                          ),
                                        ),
                                      ),
                                      position: PreferredPosition.top,
                                      pressType: PressType.longPress,
                                      verticalMargin: -5,
                                      controller: _popupMenuController,
                                    ),
                                  ]);
                            }),
                            Divider(
                              thickness: 0.5,
                            ),
                            //최근 댓글 1개 미리보기
                            items[index].comments.length == 0
                                ? Container()
                                : Padding(
                                    padding: EdgeInsets.fromLTRB(3, 1, 3, 1),
                                    child: Row(
                                      children: [
                                        Text(
                                          items[index]
                                              .comments[0]
                                              .commenterName,
                                          style: TextStyle(
                                              fontWeight: FontWeight.bold),
                                        ),
                                        SizedBox(width: 3),
                                        Text(items[index].comments[0].bodytext),
                                      ],
                                    ),
                                  ),
                            //댓글 더보기
                            GestureDetector(
                                onTap: () {
                                  Navigator.push(
                                      context,
                                      MaterialPageRoute(
                                        builder: (context) => SNSCommentView(),
                                      ));
                                },
                                child: Padding(
                                  padding: EdgeInsets.fromLTRB(3, 1, 3, 2),
                                  child: items[index].comments.length == 0
                                      ? Text('첫 댓글을 달아주세요')
                                      : Text(
                                          '댓글 ${items[index].comments.length.toString()}개 모두 보기'),
                                ))
                          ],
                        ),
                      ),
                    ),
                  );
                },
              ),
              floatingActionButton: FloatingActionButton(
                onPressed: () {
                  _showMyDialog();
                },
                child: const Icon(Icons.add),
                backgroundColor: Color((0xffF07B3F)),
              ),
            );
          } else {
            return CircularProgressIndicator();
          }
        });
  }
}
