<?php
    session_start();
    if (!($_SESSION['loggued_on_user']))
        echo "ERROR\n";
    else {
        if ($_POST['msg']) 
        {
            if (!file_exists('../private'))
            {
                mkdir("../private");
                file_put_contents('../private/chat', null);
            }           
            $chat = unserialize(file_get_contents('../private/chat'));
            $fp = fopen('../private/chat', "w");
            flock($fp, LOCK_EX);
			date_default_timezone_set('Europe/Helsinki');
            $new_msg['login'] = $_SESSION['loggued_on_user'];
            $new_msg['time'] = time();
            $new_msg['msg'] = $_POST['msg'];
            $chat[] = $new_msg;
            file_put_contents('../private/chat', serialize($chat));
            fclose($fp);
        }
    }
?>


<html>
    <head>
        <script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
    </head>
    <body>
        <form action="speak.php" method="POST">
        <input type="text" name="msg" value=""/><input type="submit" name="submit" value="Send"/>
        </form>
    </body>
</html>
