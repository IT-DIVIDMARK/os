<!-- <?php

$xml =  simplexml_load_file("book.xml") or die("Error : File Does Not Support");

echo "<h2>Book Information</h2>";

foreach ($xml -> book as $book)
{
    echo "<strong>Book Title:</strong>" . $book -> title . "<br>";
    echo "<strong>Author:</strong>" . $book -> author . "<br>";
    echo "<strong>Publisher:</strong>" . $book -> publisher . "<br>";
    echo "<strong>Price:</strong>" . $book -> price . "<br>";

    echo "<hr>";
}

?> -->

<?php
    $xml = simplexml_load_file("book.xml") or die("Error : File not Support");
    echo "<h2>Book Information</h2>";
    foreach ($xml -> book as $book)
    {
        echo "<strong>Book Title:</strong> . $book -> title . <br>";
        echo "<strong>Book Author:</strong> . $book -> author . <br>";
        echo "<strong>Book Publisher:</strong> . $book -> publisher . <br>";
        echo "<strong>Book Price:</strong> . $book -> price . <br>";

        echo "<hr>";
    }
?>