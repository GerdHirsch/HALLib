<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html>
			<head>
				<title></title>
			</head>
			<body>
				<xsl:for-each select="Contexts/Context">
					<table width="500" border="1">
					<th><xsl:value-of select="@name"/></th>
					<!--  Tabellenheader -->
					<xsl:for-each select="Columns/Column">
						<th><xsl:value-of select="@name"/></th>
					</xsl:for-each>
					<!--  Tabelleninhalt -->
					<xsl:for-each select="Rows/Row">
						<xsl:variable name="rowName" select="@name"/>
						<tr>
							<td><xsl:value-of select="@name"/></td>
							<xsl:for-each select="../../Columns/Column">
								<xsl:variable name="colName" select="@name"/>
								<td>
									<xsl:value-of select="../..//*[@column = $colName and @row = $rowName]/@content"/>
								</td>
							</xsl:for-each>
						</tr>
					</xsl:for-each>
					</table>
				</xsl:for-each>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
