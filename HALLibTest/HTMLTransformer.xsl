<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html>
			<head>
				<title>Spezialisierungen für Context</title>
				<style type="text/css">
				<!--
				/* Hier werden die Formate definiert */
				
				-->
				</style>
			</head>
			<body>
				<xsl:for-each select="Contexts/Context">
					<h3>Context
					<br/><xsl:value-of select="@name"/></h3>
					<table width="98%" border="2" rules="all">
					<th style="font-size:80%" align="center">Context</th>
					<!--  Tabellenheader -->
					<xsl:for-each select="Columns/Column">
						<th style="font-size:80%"><xsl:value-of select="@name"/></th>
					</xsl:for-each>
					<!--  Tabelleninhalt -->
					<xsl:for-each select="Rows/Row">
						<xsl:variable name="rowName" select="@name"/>
						<tr>
							<td style="font-size:80%" align="center"><xsl:value-of select="@name"/></td>
							<xsl:for-each select="../../Columns/Column">
								<xsl:variable name="colName" select="@name"/>
								<td style="font-size:80%" width="300" align="center">
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
