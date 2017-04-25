<html><body>

Hello,<br>
you requested the path: {path}
<p>
And your web browser provided the following headers:
<p>
{loop header}
  <b>{header.name}:</b> {header.value}<br>
{end header}

</html></body>
